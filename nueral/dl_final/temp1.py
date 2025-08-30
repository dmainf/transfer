import os
import time
from tqdm import tqdm
import torchvision.models as models
import numpy as np
from PIL import Image
import torch
import torch.nn as nn
from torch import optim
import torch.utils.data as data
from torch.utils.data import DataLoader
from torchvision.datasets import VisionDataset
from torchvision import transforms
from torchvision.transforms import functional as TF
from torch.nn import functional as F
from torchvision.transforms import InterpolationMode
from torch.cuda.amp import autocast, GradScaler
from dataclasses import dataclass
import random
import shutil
import zipfile

# カラーマップ生成関数：セグメンテーションの可視化用
def colormap(N=256, normalized=False):
    def bitget(byteval, idx):
        return ((byteval & (1 << idx)) != 0)

    dtype = 'float32' if normalized else 'uint8'
    cmap = np.zeros((N, 3), dtype=dtype)
    for i in range(N):
        r = g = b = 0
        c = i
        for j in range(8):
            r = r | (bitget(c, 0) << 7-j)
            g = g | (bitget(c, 1) << 7-j)
            b = b | (bitget(c, 2) << 7-j)
            c = c >> 3

        cmap[i] = np.array([r, g, b])

    cmap = cmap/255 if normalized else cmap
    return cmap

# NYUv2データセット：データ拡張と前処理をクラス内に統合
class NYUv2(VisionDataset):
    """NYUv2 dataset with integrated data augmentation

    Args:
        root (string): Root directory path.
        split (string, optional): 'train' for training set, and 'test' for test set.
        image_size (tuple): The target size for the images (height, width).
        include_depth (bool): If True, includes depth images in the output.
        normalize_mean (tuple): Mean for normalization.
        normalize_std (tuple): Standard deviation for normalization.
    """
    cmap = colormap()
    def __init__(self,
                 root,
                 split='train',
                 image_size=(256, 256),
                 include_depth=False,
                 normalize_mean=(0.485, 0.456, 0.406),
                 normalize_std=(0.229, 0.224, 0.225),
                 ):
        super(NYUv2, self).__init__(root)

        assert(split in ('train', 'test'))
        self.root = root
        self.split = split
        self.image_size = image_size
        self.include_depth = include_depth
        self.normalize = transforms.Normalize(mean=normalize_mean, std=normalize_std)
        self.to_tensor = transforms.ToTensor()
        
        # データ拡張用のTransform
        self.color_jitter = transforms.ColorJitter(brightness=0.4, contrast=0.4, saturation=0.4, hue=0.1)
        self.random_affine = transforms.RandomAffine(degrees=(-10, 10), translate=(0.1, 0.1), shear=(-5, 5))

        # 画像ファイルのパスリストを作成
        img_names = os.listdir(os.path.join(self.root, self.split, 'image'))
        img_names.sort()
        images_dir = os.path.join(self.root, self.split, 'image')
        self.images = [os.path.join(images_dir, name) for name in img_names]

        if self.split == 'train':
            label_dir = os.path.join(self.root, self.split, 'label')
            self.labels = [os.path.join(label_dir, name) for name in img_names]
            self.targets = self.labels

        if self.include_depth:
            depth_dir = os.path.join(self.root, self.split, 'depth')
            self.depths = [os.path.join(depth_dir, name) for name in img_names]

    def __getitem__(self, idx):
        image = Image.open(self.images[idx]).convert('RGB')
        if self.include_depth:
            depth = Image.open(self.depths[idx])

        if self.split == 'train':
            target = Image.open(self.targets[idx])

            # --- データ拡張 ---
            # 1. RandomResizedCrop
            i, j, h, w = transforms.RandomResizedCrop.get_params(image, scale=(0.5, 1.0), ratio=(3./4., 4./3.))
            image = TF.resized_crop(image, i, j, h, w, self.image_size, InterpolationMode.BILINEAR)
            target = TF.resized_crop(target, i, j, h, w, self.image_size, InterpolationMode.NEAREST)
            if self.include_depth:
                depth = TF.resized_crop(depth, i, j, h, w, self.image_size, InterpolationMode.BILINEAR)

            # 2. RandomHorizontalFlip
            if random.random() > 0.5:
                image = TF.hflip(image)
                target = TF.hflip(target)
                if self.include_depth:
                    depth = TF.hflip(depth)
            
            # 3. RandomRotation
            angle = transforms.RandomRotation.get_params([-10, 10])
            image = TF.rotate(image, angle, interpolation=InterpolationMode.BILINEAR)
            target = TF.rotate(target, angle, interpolation=InterpolationMode.NEAREST)
            if self.include_depth:
                depth = TF.rotate(depth, angle, interpolation=InterpolationMode.BILINEAR)

            # 4. RandomAffine
            # Apply affine transformation
            image = self.random_affine(image)
            target = self.random_affine(target)
            if self.include_depth:
                depth = self.random_affine(depth)

            # 5. ColorJitter (画像にのみ適用)
            image = self.color_jitter(image)

            # --- テンソル化と正規化 ---
            image = self.to_tensor(image)
            image = self.normalize(image)
            target = torch.from_numpy(np.array(target)).long()
            if self.include_depth:
                depth = self.to_tensor(depth)
                return image, depth, target
            return image, target

        else: # 'test' split
            # テスト時はリサイズのみ
            image = TF.resize(image, self.image_size, InterpolationMode.BILINEAR)
            image = self.to_tensor(image)
            image = self.normalize(image)
            if self.include_depth:
                depth = TF.resize(depth, self.image_size, InterpolationMode.BILINEAR)
                depth = self.to_tensor(depth)
                return image, depth
            return image


    def __len__(self):
        return len(self.images)

# 2つの畳み込み層とバッチ正規化、ReLUを含むブロック
class DoubleConv(nn.Module):
    def __init__(self, in_channels, out_channels):
        super().__init__()
        self.double_conv = nn.Sequential(
            nn.Conv2d(in_channels, out_channels, kernel_size=3, padding=1),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True),
            nn.Conv2d(out_channels, out_channels, kernel_size=3, padding=1),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True),
        )

    def forward(self, x):
        return self.double_conv(x)

class DiceLoss(nn.Module):
    def __init__(self, num_classes, ignore_index=255, smooth=1e-6):
        super(DiceLoss, self).__init__()
        self.num_classes = num_classes
        self.ignore_index = ignore_index
        self.smooth = smooth

    def forward(self, inputs, targets):
        # inputs: (N, C, H, W), targets: (N, H, W)

        # Create a mask for valid pixels (not ignore_index)
        valid_mask = (targets != self.ignore_index)

        # Convert targets to one-hot encoding for valid pixels
        # Temporarily set ignore_index to 0 for one_hot, then mask out
        targets_for_one_hot = targets.clone()
        targets_for_one_hot[~valid_mask] = 0 # Set ignored pixels to a valid class (e.g., 0) temporarily
        targets_one_hot = F.one_hot(targets_for_one_hot, num_classes=self.num_classes).permute(0, 3, 1, 2).contiguous().float()

        # Apply softmax to inputs to get probabilities
        inputs = F.softmax(inputs, dim=1)

        # Apply valid mask to both inputs and targets_one_hot
        inputs = inputs * valid_mask.unsqueeze(1).float()
        targets_one_hot = targets_one_hot * valid_mask.unsqueeze(1).float()

        # Flatten label and prediction tensors
        inputs = inputs.view(-1, self.num_classes)
        targets_one_hot = targets_one_hot.view(-1, self.num_classes)

        intersection = (inputs * targets_one_hot).sum(0)
        union = inputs.sum(0) + targets_one_hot.sum(0)

        dice = (2. * intersection + self.smooth) / (union + self.smooth)
        return 1 - dice.mean()

# UNetモデル
import torchvision.models as models

class UNet(nn.Module):
    def __init__(self, in_channels, num_classes):
        super().__init__()
        # Load pre-trained ResNet50 as encoder
        resnet = models.resnet50(weights=models.ResNet50_Weights.IMAGENET1K_V1)

        # Modify the first conv layer to accept 'in_channels' (e.g., 4 for RGBD)
        self.initial_conv = nn.Conv2d(in_channels, 64, kernel_size=7, stride=2, padding=3, bias=False)
        self.initial_bn = resnet.bn1
        self.initial_relu = resnet.relu
        self.maxpool = resnet.maxpool

        # Encoder blocks from ResNet
        self.layer1 = resnet.layer1 # 256 channels for ResNet50
        self.layer2 = resnet.layer2 # 512 channels
        self.layer3 = resnet.layer3 # 1024 channels
        self.layer4 = resnet.layer4 # 2048 channels

        # Decoder parts - adjusted for ResNet50 output channels
        self.up = nn.Upsample(scale_factor=2, mode='bilinear', align_corners=False)
        self.dec4 = DoubleConv(2048 + 1024, 1024) # From layer4 and layer3
        self.dec3 = DoubleConv(1024 + 512, 512) # From dec4 and layer2
        self.dec2 = DoubleConv(512 + 256, 256)   # From dec3 and layer1
        self.dec1 = DoubleConv(256 + 64, 128)    # From dec2 and initial_conv output (after maxpool)

        # Final output layer
        self.final = nn.Conv2d(128, num_classes, kernel_size=1)

    def forward(self, x):
        # Encoder
        x0 = self.initial_conv(x)
        x0 = self.initial_bn(x0)
        x0 = self.initial_relu(x0)
        e1 = self.maxpool(x0) # Output of initial conv and maxpool, 64 channels

        e2 = self.layer1(e1) # 64 channels
        e3 = self.layer2(e2) # 128 channels
        e4 = self.layer3(e3) # 256 channels
        e5 = self.layer4(e4) # 512 channels

        # Decoder
        # Ensure spatial dimensions match before concatenation
        d4 = self.dec4(torch.cat([self.up(e5), F.interpolate(e4, size=self.up(e5).shape[2:], mode='bilinear', align_corners=False)], dim=1))
        d3 = self.dec3(torch.cat([self.up(d4), F.interpolate(e3, size=self.up(d4).shape[2:], mode='bilinear', align_corners=False)], dim=1))
        d2 = self.dec2(torch.cat([self.up(d3), F.interpolate(e2, size=self.up(d3).shape[2:], mode='bilinear', align_corners=False)], dim=1))
        d1 = self.dec1(torch.cat([self.up(d2), F.interpolate(e1, size=self.up(d2).shape[2:], mode='bilinear', align_corners=False)], dim=1)) # e1 is the output after initial conv and maxpool

        return self.final(d1)

# config
@dataclass
class TrainingConfig:
    dataset_root: str = "data"
    batch_size: int = 32
    num_workers: int = 4
    in_channels: int = 3
    num_classes: int = 13
    epochs: int = 1
    learning_rate: float = 0.001
    weight_decay: float = 1e-4
    device: str = "cuda" if torch.cuda.is_available() else "cpu"
    checkpoint_dir: str = "checkpoints"
    save_interval: int = 5
    image_size: tuple = (256, 256)
    normalize_mean: tuple = (0.485, 0.456, 0.406)
    normalize_std: tuple = (0.229, 0.224, 0.225)
    class_weights_path: str = "class_weights.pt"

    def __post_init__(self):
        os.makedirs(self.checkpoint_dir, exist_ok=True)

def set_seed(seed):
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False

def prepare_data(data_zip_path='data.zip', data_dir='data', train_dir='train', test_dir='test'):
    if not os.path.exists(data_zip_path):
        print(f"Warning: {data_zip_path} not found. Skipping data preparation.")
        return
    if os.path.exists(data_dir):
        print("Data directory already exists. Skipping data preparation.")
        return

    print("Unzipping data...")
    with zipfile.ZipFile(data_zip_path, 'r') as zip_ref:
        zip_ref.extractall('.')
    if not os.path.exists(data_dir):
        os.makedirs(data_dir)
    for d in [train_dir, test_dir]:
        source_path = d
        dest_path = os.path.join(data_dir, d)
        if os.path.exists(source_path):
            if os.path.exists(dest_path):
                shutil.rmtree(dest_path)
            shutil.move(source_path, data_dir)
            print(f"Moved {source_path} to {data_dir}/")

def get_class_weights(dataset, num_classes, weights_path, ignore_index=255):
    if os.path.exists(weights_path):
        print(f"Loading class weights from {weights_path}")
        weights = torch.load(weights_path)
        return weights

    print("Calculating class weights...")
    loader = DataLoader(dataset, batch_size=1, shuffle=False, num_workers=0)
    class_counts = torch.zeros(num_classes, dtype=torch.float)
    
    for _, _, label in tqdm(loader, desc="Counting classes"):
        label = label.squeeze(0)
        mask = label != ignore_index
        active_labels = label[mask]
        class_counts += torch.bincount(active_labels, minlength=num_classes)

    total_pixels = class_counts.sum()
    class_frequencies = class_counts / total_pixels
    median_frequency = torch.median(class_frequencies[class_counts > 0])
    
    weights = median_frequency / (class_frequencies + 1e-6)
    weights[class_counts == 0] = 0 
    
    torch.save(weights, weights_path)
    print(f"Class weights saved to {weights_path}")
    print(f"Weights: {weights}")
    return weights


# --- Main execution ---
if __name__ == '__main__':
    set_seed(42)
    prepare_data()

    # CPUコア数を取得し、num_workersに設定
    try:
        num_cpu_cores = len(os.sched_getaffinity(0))
    except AttributeError:
        num_cpu_cores = os.cpu_count()
    print(f"Using {num_cpu_cores} CPU cores for data loading.")

    config = TrainingConfig(
        dataset_root='data',
        batch_size=4,
        num_workers=num_cpu_cores, # CPUコア数を設定
        learning_rate=1e-4,
        epochs=1,
        image_size=(240, 320), # H, W
        in_channels=4
    )

    # --- Dataloader ---
    train_dataset = NYUv2(
        root=config.dataset_root,
        split='train',
        image_size=config.image_size,
        include_depth=True,
        normalize_mean=config.normalize_mean,
        normalize_std=config.normalize_std
    )
    test_dataset = NYUv2(
        root=config.dataset_root,
        split='test',
        image_size=config.image_size,
        include_depth=True,
        normalize_mean=config.normalize_mean,
        normalize_std=config.normalize_std
    )

    train_data = DataLoader(train_dataset, batch_size=config.batch_size, shuffle=True, num_workers=config.num_workers, pin_memory=True)
    test_data = DataLoader(test_dataset, batch_size=1, shuffle=False, num_workers=config.num_workers, pin_memory=True)

    device = config.device
    print(f"Using device: {device}")

    # --- Model ---
    model = UNet(in_channels=config.in_channels, num_classes=config.num_classes).to(device)

    # --- Loss Function with Class Weights and Dice Loss ---
    class_weights = get_class_weights(train_dataset, config.num_classes, config.class_weights_path).to(device)
    ce_criterion = nn.CrossEntropyLoss(weight=class_weights, ignore_index=255)
    dice_criterion = DiceLoss(num_classes=config.num_classes, ignore_index=255)

    # --- Optimizer & Scheduler ---
    optimizer = optim.Adam(model.parameters(), lr=config.learning_rate, weight_decay=config.weight_decay)
    scheduler = optim.lr_scheduler.CosineAnnealingLR(optimizer, T_max=config.epochs, eta_min=1e-6)

    # --- Training ---
    scaler = GradScaler()
    model.train()
    for epoch in range(config.epochs):
        total_loss = 0
        print(f"on epoch: {epoch+1}/{config.epochs} | LR: {scheduler.get_last_lr()[0]:.6f}")
        with tqdm(train_data, desc=f"Epoch {epoch+1}") as pbar:
            for image, depth, label in pbar:
                image, depth, label = image.to(device), depth.to(device), label.to(device)
                optimizer.zero_grad()

                with autocast():
                  x = torch.cat((image, depth), dim=1)
                  pred = model(x)
                  # Resize label to match prediction size
                  label_resized = F.interpolate(label.unsqueeze(1).float(), size=pred.shape[2:], mode='nearest').squeeze(1).long()
                  
                  ce_loss = ce_criterion(pred, label_resized)
                  dice_loss = dice_criterion(pred, label_resized)
                  loss = ce_loss + dice_loss

                scaler.scale(loss).backward()
                scaler.step(optimizer)
                scaler.update()

                total_loss += loss.item()
                pbar.set_postfix(loss=loss.item())
        
        scheduler.step() # Update learning rate
        print(f'Epoch {epoch+1}, Average Loss: {total_loss / len(train_data)}')

    # --- Save Model ---
    current_time = time.strftime("%Y%m%d%H%M%S")
    model_path = f"model_{current_time}.pt"
    torch.save(model.state_dict(), model_path)
    print(f"Model saved to {model_path}")

    # --- Evaluation ---
    model.load_state_dict(torch.load(model_path, map_location=device))
    model.eval()
    predictions = []
    with torch.no_grad():
        print("Generating predictions...")
        for image, depth in tqdm(test_data):
            image, depth = image.to(device), depth.to(device)
            x = torch.cat((image, depth), dim=1)
            output = model(x)
            pred = output.argmax(dim=1)
            predictions.append(pred.cpu())
    predictions = torch.cat(predictions, dim=0)
    predictions = predictions.cpu().numpy()
    np.save('submission.npy', predictions)
    print("Predictions saved to submission.npy")

    # --- Submission ---
    notebook_path = "temp.py"
    print("Creating submission.zip...")
    with zipfile.ZipFile("submission.zip", mode="w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as zf:
        zf.write("submission.npy")
        zf.write(model_path)
        zf.write(notebook_path, arcname="DL_Basic_2025_Competition_NYUv2_baseline.ipynb")
    print("submission.zip created successfully.")