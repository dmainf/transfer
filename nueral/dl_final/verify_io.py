import numpy as np
import zipfile
import os
import torch
from torch.utils.data import DataLoader

# temp.pyから必要なコンポーネントをインポート
from temp import NYUv2, TrainingConfig, prepare_data, set_seed

def verify_io():
    print("--- 設定開始 ---")
    set_seed(42)
    # データ準備（zip展開など）
    prepare_data()

    config = TrainingConfig(
        dataset_root='data',
        batch_size=1, 
        num_workers=0,
        image_size=(240, 320),
        in_channels=4
    )

    print("\n--- データ読み込み検証 ---")
    try:
        test_dataset = NYUv2(
            root=config.dataset_root,
            split='test',
            image_size=config.image_size,
            include_depth=True,
            normalize_mean=config.normalize_mean,
            normalize_std=config.normalize_std
        )
        test_data = DataLoader(test_dataset, batch_size=config.batch_size, shuffle=False, num_workers=config.num_workers)

        # 1サンプルだけ読み込んでみる
        image, depth = next(iter(test_data))
        print("テストデータの1バッチの読み込みに成功しました。")
        print(f"画像 Shape: {image.shape}, 深度 Shape: {depth.shape}")
        num_test_samples = len(test_dataset)
        print(f"テストサンプル総数: {num_test_samples}")

    except Exception as e:
        print(f"失敗: データ読み込みチェックがエラーで失敗しました: {e}")
        return

    print("\n--- 結果書き込み検証 ---")
    try:
        # ダミーの予測とモデルファイルを作成
        dummy_predictions = np.random.randint(0, config.num_classes, size=(num_test_samples, config.image_size[0], config.image_size[1]), dtype=np.uint8)
        np.save('submission.npy', dummy_predictions)
        print("submission.npy の保存に成功しました。")

        model_path = "dummy_model.pt"
        with open(model_path, "w") as f:
            f.write("dummy model")
        print("dummy_model.pt の作成に成功しました。")

        notebook_path = "temp.py"
        zip_path = "submission.zip"
        with zipfile.ZipFile(zip_path, mode="w", compression=zipfile.ZIP_DEFLATED, compresslevel=9) as zf:
            zf.write("submission.npy")
            zf.write(model_path)
            zf.write(notebook_path, arcname="DL_Basic_2025_Competition_NYUv2_baseline.ipynb")
        print(f"{zip_path} の作成に成功しました。")

    except Exception as e:
        print(f"失敗: 結果書き込みチェックがエラーで失敗しました: {e}")
    finally:
        # クリーンアップ
        if os.path.exists('submission.npy'):
            os.remove('submission.npy')
        if os.path.exists(model_path):
            os.remove(model_path)
        if os.path.exists(zip_path):
            os.remove(zip_path)
        print("\n一時ファイルをクリーンアップしました。")

if __name__ == "__main__":
    verify_io()
