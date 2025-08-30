import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier, VotingClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve, auc, roc_auc_score, classification_report
from imblearn.over_sampling import SMOTE
from sklearn.utils import shuffle
import lightgbm as lgb
import optuna
import warnings
warnings.filterwarnings('ignore')

from lib.prepro import clean_data, one_hot_encoding, merge_df
from lib.feature_eng import feature_engineering, feature_group_diff

df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')

print("=== データ前処理開始 ===")
df = clean_data(df_raw.copy())
df = df.drop(columns=['CustomerID'])
feature_df = df.drop(columns=['Churn'])
target_df = df['Churn']
print(df.info())

print("=== 現状の解約率 ===")
Churn_rate = df['Churn'].value_counts() / df.shape[0]
plt.figure(figsize=(8, 6))
labels = Churn_rate.index.map({0:'Existing', 1:"Churn"})
percentages = Churn_rate.values * 100
plt.bar(labels, percentages)
plt.xlabel('Customers')
plt.ylabel('Percentage (%)')
plt.title('Customer Distribution')
plt.ylim(0, 100)
for i, v in enumerate(percentages):
    plt.text(i, v + 1, f'{v:.1f}%', ha='center', va='bottom')
plt.show()