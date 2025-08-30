import os
import time
from tqdm import tqdm
import numpy as np
from PIL import Image
import torch
import torch.nn as nn
from torch import optim
import torch.utils.data as data
from torch.utils.data import DataLoader
from torchvision.datasets import VisionDataset
from torchvision import transforms
from torchvision.transforms import functional as F
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
            image = F.resized_crop(image, i, j, h, w, self.image_size, InterpolationMode.BILINEAR)
            target = F.resized_crop(target, i, j, h, w, self.image_size, InterpolationMode.NEAREST)
            if self.include_depth:
                depth = F.resized_crop(depth, i, j, h, w, self.image_size, InterpolationMode.BILINEAR)

            # 2. RandomHorizontalFlip
            if random.random() > 0.5:
                image = F.hflip(image)
                target = F.hflip(target)
                if self.include_depth:
                    depth = F.hflip(depth)
            
            # 3. ColorJitter (画像にのみ適用)
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
            image = F.resize(image, self.image_size, InterpolationMode.BILINEAR)
            image = self.to_tensor(image)
            image = self.normalize(image)
            if self.include_depth:
                depth = F.resize(depth, self.image_size, InterpolationMode.BILINEAR)
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

# UNetモデル
class UNet(nn.Module):
    def __init__(self, in_channels, num_classes):
        super().__init__()
        self.enc1 = DoubleConv(in_channels, 64)
        self.enc2 = DoubleConv(64, 128)
        self.enc3 = DoubleConv(128, 256)
        self.enc4 = DoubleConv(256, 512)
        self.pool = nn.MaxPool2d(2)
        self.up = nn.Upsample(scale_factor=2, mode='bilinear', align_corners=False)
        self.dec3 = DoubleConv(512 + 256, 256)
        self.dec2 = DoubleConv(256 + 128, 128)
        self.dec1 = DoubleConv(128 + 64, 64)
        self.final = nn.Conv2d(64, num_classes, kernel_size=1)

    def forward(self, x):
        e1 = self.enc1(x)
        e2 = self.enc2(self.pool(e1))
        e3 = self.enc3(self.pool(e2))
        e4 = self.enc4(self.pool(e3))
        d3 = self.dec3(torch.cat([self.up(e4), e3], dim=1))
        d2 = self.dec2(torch.cat([self.up(d3), e2], dim=1))
        d1 = self.dec1(torch.cat([self.up(d2), e1], dim=1))
        return self.final(d1)

# config
@dataclass
class TrainingConfig:
    dataset_root: str = "data"
    batch_size: int = 32
    num_workers: int = 4
    in_channels: int = 3
    num_classes: int = 13
    epochs: int = 100
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

    # --- Loss Function with Class Weights ---
    class_weights = get_class_weights(train_dataset, config.num_classes, config.class_weights_path).to(device)
    criterion = nn.CrossEntropyLoss(weight=class_weights, ignore_index=255)

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
                  loss = criterion(pred, label)

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