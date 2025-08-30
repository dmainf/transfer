import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim

path     = 'pokedex.csv'
data = pd.read_csv(path)


#remove "Mega" pokemon
data = data[~data['name'].str.startswith('Mega', na=False)]


#drop culunm
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


#label encoding
from sklearn.preprocessing import LabelEncoder
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


# fill NaN
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


from sklearn.preprocessing import StandardScaler
from sklearn.compose import ColumnTransformer
numeric_cols = data.select_dtypes(include=['number']).columns
non_numeric_cols = data.select_dtypes(exclude=['number']).columns

preprocessor = ColumnTransformer(
    transformers=[
        ('num', StandardScaler(), numeric_cols)
    ],
    remainder='passthrough'
)
data_processed = preprocessor.fit_transform(data)
data_scaled = pd.DataFrame(data_processed, columns=preprocessor.get_feature_names_out())

#One-Hot encoding
# The non-numeric columns passed through the ColumnTransformer are already in data_scaled.
# We need to apply one-hot encoding to these categorical columns.
categorical_cols = [col for col in data_scaled.columns if data_scaled[col].dtype == 'object']
data_encoded = pd.get_dummies(data_scaled, columns=categorical_cols)

from sklearn.decomposition import PCA

# Use PCA to determine the optimal number of dimensions
pca = PCA(n_components=0.95)
pca.fit(data_encoded)
encoding_dim = pca.n_components_
print(f"Selected encoding dimension based on PCA (95% variance): {encoding_dim}")


# Autoencoder implementation
# Convert data to PyTorch tensor
data_tensor = torch.tensor(data_encoded.values, dtype=torch.float32)

# Define the Autoencoder model
class Autoencoder(nn.Module):
    def __init__(self, input_dim, encoding_dim):
        super(Autoencoder, self).__init__()
        self.encoder = nn.Sequential(
            nn.Linear(input_dim, 128),
            nn.ReLU(),
            nn.Linear(128, 64),
            nn.ReLU(),
            nn.Linear(64, encoding_dim)
        )
        self.decoder = nn.Sequential(
            nn.Linear(encoding_dim, 64),
            nn.ReLU(),
            nn.Linear(64, 128),
            nn.ReLU(),
            nn.Linear(128, input_dim)
        )

    def forward(self, x):
        encoded = self.encoder(x)
        decoded = self.decoder(encoded)
        return decoded

    def encode(self, x):
        return self.encoder(x)

# Model, loss, and optimizer
input_dim = data_tensor.shape[1]
# encoding_dim is now set by PCA
autoencoder = Autoencoder(input_dim, encoding_dim)
criterion = nn.MSELoss()
optimizer = optim.Adam(autoencoder.parameters(), lr=0.001)

# Training the autoencoder
num_epochs = 100
batch_size = 32
for epoch in range(num_epochs):
    for i in range(0, len(data_tensor), batch_size):
        batch = data_tensor[i:i+batch_size]
        outputs = autoencoder(batch)
        loss = criterion(outputs, batch)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

    if (epoch+1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')

# Get the encoded data
with torch.no_grad():
    data_pca = autoencoder.encode(data_tensor).numpy()


from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
distortions = []
K = range(1, 30)
for k in K:
    kmeans_model = KMeans(n_clusters=k, n_init='auto', random_state=42)
    kmeans_model.fit(data_pca)
    distortions.append(kmeans_model.inertia_)

plt.figure(figsize=(10, 6))
plt.plot(K, distortions, 'bx-')
plt.grid(True)
#plt.show()

optimal_k = 7

kmeans = KMeans(n_clusters=optimal_k, n_init='auto', random_state=42)
clusters = kmeans.fit_predict(data_pca)
data['cluster'] = clusters

type_tmp = pd.get_dummies(data['type_1'])
data_with_types = pd.concat([data['cluster'], type_tmp], axis=1)
cluster_type_counts = data_with_types.groupby('cluster').sum()
cluster_sizes = data['cluster'].value_counts().sort_index()
type_percentages = cluster_type_counts.div(cluster_sizes, axis=0) * 100

rows = (optimal_k + 2) // 3
fig, axes = plt.subplots(rows, 3, figsize=(18, 6 * rows))
axes = axes.flatten()
for i, cluster_id in enumerate(type_percentages.index):
    ax = axes[i]
    series = type_percentages.loc[cluster_id]
    threshold = 5.0
    significant_types = series[series >= threshold]
    ax.pie(significant_types,
           labels=significant_types.index,
           autopct='%1.1f%%',
           startangle=90,
           counterclock=False,
           wedgeprops={'linewidth': 1, 'edgecolor':"white"})
    ax.set_title(f'cluster {cluster_id}', fontsize=14)
for j in range(i + 1, len(axes)):
    fig.delaxes(axes[j])
plt.tight_layout()
#plt.show()


import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D # 3Dプロット用のライブラリをインポート
import seaborn as sns

if data_pca.shape[1] < 3:
    print("データが3次元未満のため、3Dプロットは作成できません.")
else:
    fig = plt.figure(figsize=(12, 10))
    ax = fig.add_subplot(111, projection='3d')
    palette = sns.color_palette('bright', n_colors=optimal_k)
    for i, cluster_id in enumerate(sorted(data['cluster'].unique())):
        cluster_data = data_pca[data['cluster'] == cluster_id]
        ax.scatter(cluster_data[:, 0],   # X軸: 第1主成分
                   cluster_data[:, 1],   # Y軸: 第2主成分
                   cluster_data[:, 2],   # Z軸: 第3主成分
                   color=palette[i],
                   label=f'Cluster {cluster_id}')
    ax.set_title('3D Cluster Visualization using Autoencoder')
    ax.set_xlabel('Encoded Dimension 1')
    ax.set_ylabel('Encoded Dimension 2')
    ax.set_zlabel('Encoded Dimension 3')
    ax.legend()

plt.show()