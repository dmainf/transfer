import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import seaborn as sns
from sklearn.preprocessing import LabelEncoder, StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans

path     = 'pokedex.csv'
data = pd.read_csv(path)


# --- Data Cleaning and Preprocessing ---

data = data[~data['name'].str.startswith('Mega', na=False)]
#data = data[data['status'] == 'Normal']

drop_cols = [
    'Unnamed: 0',
    'pokedex_number',
    'name',
    'japanese_name',
    'german_name',
    'egg_type_2',
    'type_number',
    'against_normal',
    'against_fire',
    'against_water',
    'against_electric',
    'against_grass',
    'against_ice',
    'against_fight',
    'against_poison',
    'against_ground',
    'against_flying',
    'against_psychic',
    'against_bug',
    'against_rock',
    'against_ghost',
    'against_dragon',
    'against_dark',
    'against_steel',
    'against_fairy',
    'type_2'
    ]
data.drop(drop_cols, axis=1, inplace=True)

mapping = {
    'nan'          : 0,
    'Fluctuating'  : 1,
    'Slow'         : 2,
    'Medium Slow'  : 3,
    'Medium Fast'  : 4,
    'Fast'         : 5,
    'Erratic'      : 6
}
data['growth_rate'] = data['growth_rate'].fillna('nan').astype(str).map(mapping)

data['species'] = data['species'].str.replace(r'\s*Pok[eé]mon$', '', regex=True)
data['species'] = data['species'].map(data['species'].value_counts())

data['ability_1'] = data['ability_1'].map(data['ability_1'].value_counts())
data['ability_2'] = data['ability_2'].map(data['ability_2'].value_counts()).fillna(0)
data['ability_hidden'] = data['ability_hidden'].map(data['ability_hidden'].value_counts()).fillna(0)

fill_na_cols = [
    'catch_rate',
    'base_friendship',
    'base_experience',
    'weight_kg',
    'ability_1',
    'egg_cycles',
]
for col in fill_na_cols:
    data[col] = data[col].fillna(data[col].mean())
data['percentage_male'] = data['percentage_male'].fillna(data['percentage_male'].mode()[0])

numeric_cols = data.select_dtypes(include=['number']).columns
categorical_cols = data.select_dtypes(exclude=['number']).columns

preprocessor = ColumnTransformer(
    transformers=[
        ('num', StandardScaler(), numeric_cols),
        ('cat', OneHotEncoder(handle_unknown='ignore'), categorical_cols)
    ])
data_encoded = preprocessor.fit_transform(data)


# --- Dimensionality Reduction ---

pca = PCA(n_components=0.9)
data_pca = pca.fit_transform(data_encoded)

"""
print("Each principal component is composed of the following features:")
for i, component in enumerate(pca.components_):
    print(f"Principal Component {i+1}:")
    feature_contributions = sorted(zip(preprocessor.get_feature_names_out(), component), key=lambda x: x[1], reverse=True)
    for feature, contribution in feature_contributions:
        print(f"  {feature}: {contribution:.4f}")
"""

# --- Clustering ---

distortions = []
K = range(1, 30)
for k in K:
    kmeans_model = KMeans(n_clusters=k, n_init='auto', random_state=42)
    kmeans_model.fit(data_pca)
    distortions.append(kmeans_model.inertia_)

plt.figure(figsize=(10, 6))
plt.plot(K, distortions, 'bx-')
plt.xlabel('Number of clusters (k)')
plt.ylabel('SSE')
plt.title('For Optimal k')
plt.grid(True)

# Based on the elbow plot, an optimal k is chosen
optimal_k = 5

kmeans = KMeans(n_clusters=optimal_k, n_init='auto', random_state=42)
clusters = kmeans.fit_predict(data_pca)
data['cluster'] = clusters


# --- Cluster Analysis and Visualization ---

type_tmp = pd.get_dummies(data['type_1'])
data_with_types = pd.concat([data['cluster'], type_tmp], axis=1)
cluster_type_counts = data_with_types.groupby('cluster').sum()
cluster_sizes = data['cluster'].value_counts().sort_index()
type_percentages = cluster_type_counts.div(cluster_sizes, axis=0) * 100

rows = (optimal_k + 2) // 3
fig, axes = plt.subplots(rows, 3, figsize=(18, 6 * rows))
axes = axes.flatten()

max_count = cluster_type_counts.values.max()+5

for i, cluster_id in enumerate(cluster_type_counts.index):
    ax = axes[i]
    series = cluster_type_counts.loc[cluster_id]
    threshold = 0
    significant_types = series[series >= threshold]

    ax.bar(significant_types.index, significant_types.values,
            color='skyblue', edgecolor='black')
    ax.set_title(f'Type Distribution in Cluster {cluster_id}', fontsize=15)
    ax.set_ylabel('Count')
    ax.tick_params(axis='x', rotation=90, labelsize=15)
    ax.set_ylim(0, max_count)
for j in range(i + 1, len(axes)):
    fig.delaxes(axes[j])
plt.tight_layout()
plt.subplots_adjust(hspace=0.4, bottom=0.12)

rows = (optimal_k + 2) // 3
fig, axes = plt.subplots(rows, 3, figsize=(18, 6 * rows))
axes = axes.flatten()
for i, cluster_id in enumerate(type_percentages.index):
    ax = axes[i]
    series = type_percentages.loc[cluster_id]
    threshold = 10.0
    significant_types = series[series >= threshold]
    ax.pie(significant_types,
        labels=significant_types.index,
        autopct='%1.1f%%',
        startangle=90,
        counterclock=False,
        wedgeprops={'linewidth': 1, 'edgecolor':"white"},
        textprops={'fontsize': 25} )
    ax.set_title(f'Type Percentage in Cluster {cluster_id}', fontsize=25)
for j in range(i + 1, len(axes)):
    fig.delaxes(axes[j])
plt.tight_layout()
plt.subplots_adjust(hspace=0.4, top=0.9)

if data_pca.shape[1] < 3:
    print("Cannot create 3D plot because the data has fewer than 3 dimensions.")
else:
    fig = plt.figure(figsize=(12, 10))
    ax = fig.add_subplot(111, projection='3d')
    palette = sns.color_palette('bright', n_colors=optimal_k)
    for i, cluster_id in enumerate(sorted(data['cluster'].unique())):
        cluster_data = data_pca[data['cluster'] == cluster_id]
        ax.scatter(cluster_data[:, 0],
                   cluster_data[:, 1],
                   cluster_data[:, 2],
                   color=palette[i],
                   label=f'Cluster {cluster_id}')
    ax.set_title('3D Cluster Visualization using PCA')
    ax.set_xlabel('Principal Component 1')
    ax.set_ylabel('Principal Component 2')
    ax.set_zlabel('Principal Component 3')
    ax.legend()

"""
# This commented block can be used to see the names of Pokémon in a specific cluster
# It requires reading the original CSV again to get the names
original_data = pd.read_csv(path)
original_data = original_data[~original_data['name'].str.startswith('Mega', na=False)]
print("\nPokémon in Cluster 4:")
print(original_data.loc[data[data['cluster'] == 4].index, 'name'])
"""
#plt.show()

# 主成分1〜3のデータフレーム作成
pca_df = pd.DataFrame(data_pca[:, :3], columns=['PC1', 'PC2', 'PC3'])
pca_df['type_1'] = data['type_1'].values

# 各タイプごとの平均を計算
type_pc_means = pca_df.groupby('type_1')[['PC1', 'PC2', 'PC3']].mean().sort_index()

# ヒートマップで可視化
plt.figure(figsize=(12, 10))
sns.heatmap(type_pc_means, annot=True, cmap='vlag', center=0, fmt=".2f", linewidths=0.5, cbar_kws={"label": "Mean Score"})
plt.title('average of PC each type', fontsize=18)
plt.xlabel('PC', fontsize=20)
plt.ylabel('type', fontsize=20)
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)
plt.tight_layout()
plt.show()
