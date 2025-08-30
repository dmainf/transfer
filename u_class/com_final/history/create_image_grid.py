

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import os

fig, axes = plt.subplots(6, 3, figsize=(36, 24))  # より大きなサイズに変更

axes = axes.flatten()

for i in range(1, 19):
    ax = axes[i-1]
    img_path = f'principal_component_{i}.png'

    if os.path.exists(img_path):
        try:
            img = mpimg.imread(img_path)
            ax.imshow(img)
        except Exception as e:
            ax.text(0.5, 0.5, f'Error loading\n{img_path}:\n{e}', ha='center', va='center')
    else:
        ax.text(0.5, 0.5, f'Image not found:\n{img_path}', ha='center', va='center')

    ax.axis('off')

# 余白を最小限に
plt.subplots_adjust(left=0, right=1, top=1, bottom=0, wspace=0.01, hspace=0.01)

output_filename = 'principal_components_grid.png'
plt.savefig(output_filename, bbox_inches='tight')  # bbox_inches='tight' を追加

print(f"Image grid saved to {output_filename}")

KMeans法（K=5）によるクラスタの解釈
Figure 13のSSE（誤差平方和）のグラフから，クラスタ数を5とした際にエルボー（肘）が形成され，それ以上クラスタを増やしても分析の効率が大きく改善しないことが確認できた．そこでK=5として分類した結果（Figure 14，Figure 15）を考察すると，各クラスタは明確な役割や特徴を持つグループを形成していた．
クラスター0（仮：序盤・一般ポケモン群）：
このクラスタは「ノーマル」「むし」「ひこう」タイプが多くを占めると推測される．これらのタイプはゲームの序盤に出現し，全体的に種族値が低めで，捕獲率が高い傾向にある．PCAで示された「強さ」や「繁殖しやすさ」の軸で類似しているため，一つのグループとして形成されたと考えられる．
クラスター1（仮：高耐久・物理ポケモン群）：
「いわ」「じめん」「はがね」といったタイプがこのクラスタの主成分である可能性が高い．これらのタイプは総じて防御やHPが高く，物理的な耐久力に優れる特徴を持つ．PCAの「強さ・耐久力」の軸で近い値を取る個体が集まった結果だろう．
クラスター2（仮：特殊アタッカー群）：
「みず」「ほのお」「くさ」「でんき」「エスパー」などがこのクラスタを構成していると考えられる．これらはタイプ相性こそ異なるが，「とくこう」が高めに設定されていることが多いという共通点を持つ．役割として「特殊攻撃のスペシャリスト」というアーキタイプで統合されたと解釈できる．
クラスター3（仮：希少・伝説ポケモン群）：
「ドラゴン」や一部の「エスパー」，伝説・幻のポケモンがこのクラスタに集中していると推測される．これらのポケモンは合計種族値が極めて高く，捕獲率が非常に低い，あるいはタマゴが見つからないなど，PCAの「強さ」と「繁殖サイクル」の軸で他のポケモンと明確に区別される．
クラスター4（仮：その他・トリッキー群）：
上記のいずれにも属さない「かくとう」「ゴースト」「あく」などが含まれる可能性がある．これらのタイプは特定のステータスに特化していたり，独特な特性を持つことが多く，特定の役割に縛られない多様なポケモン群がここに分類されたと考えられる