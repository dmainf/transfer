import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier, VotingClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve, auc, roc_auc_score
from imblearn.over_sampling import SMOTE, ADASYN
from sklearn.utils import shuffle
import warnings
warnings.filterwarnings('ignore')

# データの読み込みと前処理
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')

def clean_data(df):
    df.rename(columns={'gender':'Gender'
                       ,'customerID':'CustomerID'
                       ,'Contract':'ContractType'
                       ,'InternetService':'InternetServiceType'
                       ,'tenure':'Tenure'
                      }
              ,inplace=True)

    df['Partner'] = df.Partner.map({'Yes':1,'No':0})
    df['Dependents'] = df.Dependents.map({'Yes':1,'No':0})

    df['PhoneService'] = df.PhoneService.map({'Yes':1,'No':0})
    df['MultipleLines'] = df.MultipleLines.map({'Yes':1,'No':0,'No phone service':0})

    df['InternetService'] = df.InternetServiceType.map({'DSL':1,'Fiber optic':1,'No':0})
    df['OnlineSecurity'] = df.OnlineSecurity.map({'Yes':1,'No':0,'No internet service':0})
    df['OnlineBackup'] = df.OnlineBackup.map({'Yes':1,'No':0,'No internet service':0})
    df['DeviceProtection'] = df.DeviceProtection.map({'Yes':1,'No':0,'No internet service':0})
    df['TechSupport'] = df.TechSupport.map({'Yes':1,'No':0,'No internet service':0})
    df['StreamingTV'] = df.StreamingTV.map({'Yes':1,'No':0,'No internet service':0})
    df['StreamingMovies'] = df.StreamingMovies.map({'Yes':1,'No':0,'No internet service':0})

    df['IsContracted'] = df.ContractType.map({'One year':1,'Two year':1,'Month-to-month':0})
    df['PaperlessBilling'] = df.PaperlessBilling.map({'Yes':1,'No':0})
    df['Churn'] = df.Churn.map({'Yes':1,'No':0})

    df.loc[df['TotalCharges']==' ','TotalCharges'] = np.nan
    df['TotalCharges'] = df['TotalCharges'].astype('float64')
    df.loc[df['TotalCharges']==np.nan,'TotalCharges'] = df['MonthlyCharges'] * df['Tenure']

    return df

# 特徴量エンジニアリング
def feature_engineering(df):
    df['AvgMonthlyCharges'] = df['TotalCharges'] / (df['Tenure'] + 1)
    df['IsHighValue'] = (df['TotalCharges'] > df['TotalCharges'].quantile(0.75)).astype(int)
    df['IsLongTerm'] = (df['Tenure'] > 24).astype(int)
    df['ServicesCount'] = (df['PhoneService'] + df['MultipleLines'] + df['InternetService'] + 
                          df['OnlineSecurity'] + df['OnlineBackup'] + df['DeviceProtection'] + 
                          df['TechSupport'] + df['StreamingTV'] + df['StreamingMovies'])
    return df

clean_df = shuffle(clean_data(df_raw.copy())).reset_index()
clean_df = feature_engineering(clean_df)

# 特徴量の準備
categorical_vars = ['Gender','InternetServiceType','PaymentMethod','ContractType']
binary_vars = ['SeniorCitizen','Partner','Dependents','PhoneService','MultipleLines','OnlineSecurity','OnlineBackup'
               ,'DeviceProtection','TechSupport','StreamingTV', 'StreamingMovies','PaperlessBilling','InternetService'
               , 'IsContracted', 'IsHighValue', 'IsLongTerm']
numeric_vars = ['Tenure','MonthlyCharges', 'TotalCharges', 'AvgMonthlyCharges', 'ServicesCount']
target_var = 'Churn'

def one_hot_encoding_features_df(df, cat_feat):
    cat_df = pd.get_dummies(df[cat_feat])
    return cat_df

def merge_df(categorical=None,binary=None,numerical=None):
    return pd.concat([categorical,binary,numerical],axis = 1)

feature_df = merge_df(one_hot_encoding_features_df(clean_df,categorical_vars), clean_df[binary_vars] ,clean_df[numeric_vars])
target_df = clean_df[target_var]

# 欠損値の処理
feature_df = feature_df.fillna(feature_df.median())

# 訓練・テストデータに分割
X_train, X_test, y_train, y_test = train_test_split(feature_df, target_df, test_size=0.2, random_state=42, stratify=target_df)

# SMOTEとADASYNの準備
smote = SMOTE(random_state=42)
adasyn = ADASYN(random_state=42)
X_train_smote, y_train_smote = smote.fit_resample(X_train, y_train)
X_train_adasyn, y_train_adasyn = adasyn.fit_resample(X_train, y_train)

# モデルの定義
models = {}

# 1. 基本RandomForest (SMOTE)
rf_basic = RandomForestClassifier(
    n_estimators=100,
    max_depth=5,
    max_features=0.7,
    min_samples_leaf=5,
    oob_score=True,
    random_state=42
)
rf_basic.fit(X_train_smote, y_train_smote)
models['RF_Basic_SMOTE'] = rf_basic.predict_proba(X_test)[:, 1]

# 2. 最適化RandomForest (SMOTE)
rf_optimized = RandomForestClassifier(
    n_estimators=200,
    max_depth=7,
    max_features=0.7,
    min_samples_leaf=3,
    min_samples_split=5,
    class_weight='balanced',
    oob_score=True,
    random_state=42
)
rf_optimized.fit(X_train_smote, y_train_smote)
models['RF_Optimized_SMOTE'] = rf_optimized.predict_proba(X_test)[:, 1]

# 3. RandomForest (ADASYN)
rf_adasyn = RandomForestClassifier(
    n_estimators=200,
    max_depth=7,
    max_features=0.7,
    min_samples_leaf=3,
    min_samples_split=5,
    class_weight='balanced',
    oob_score=True,
    random_state=42
)
rf_adasyn.fit(X_train_adasyn, y_train_adasyn)
models['RF_ADASYN'] = rf_adasyn.predict_proba(X_test)[:, 1]

# 4. アンサンブル (RandomForest + GradientBoosting)
gb_model = GradientBoostingClassifier(
    n_estimators=100,
    max_depth=5,
    learning_rate=0.1,
    random_state=42
)

ensemble_model = VotingClassifier(
    estimators=[
        ('rf', rf_optimized),
        ('gb', gb_model)
    ],
    voting='soft'
)
ensemble_model.fit(X_train_smote, y_train_smote)
models['Ensemble_SMOTE'] = ensemble_model.predict_proba(X_test)[:, 1]

# ROC曲線の描画
plt.figure(figsize=(12, 8))

# 各モデルのROC曲線を描画
colors = ['blue', 'red', 'green', 'orange', 'purple']
linestyles = ['-', '--', '-.', ':', '-']

for i, (name, y_prob) in enumerate(models.items()):
    fpr, tpr, _ = roc_curve(y_test, y_prob)
    auc_score = auc(fpr, tpr)

    plt.plot(fpr, tpr, 
            color=colors[i % len(colors)], 
            linestyle=linestyles[i % len(linestyles)],
            linewidth=2,
            label=f'{name} (AUC = {auc_score:.4f})')

# ランダム予測の基準線
plt.plot([0, 1], [0, 1], 'k--', linewidth=1, label='Random (AUC = 0.5000)')

# グラフの設定
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Rate (1 - Specificity)', fontsize=12)
plt.ylabel('True Positive Rate (Sensitivity)', fontsize=12)
plt.title('ROC Curves Comparison - Different Methods', fontsize=14, fontweight='bold')
plt.legend(loc="lower right", fontsize=10)
plt.grid(True, alpha=0.3)

# 図を保存して表示
plt.tight_layout()
#plt.savefig('/home/dmainf/roc_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

# AUCスコアの詳細比較
print("=== AUC ROC Score 比較 ===")
for name, y_prob in models.items():
    auc_score = roc_auc_score(y_test, y_prob)
    print(f"{name:20s}: {auc_score:.4f}")

print("\n=== 最高性能モデル ===")
best_model = max(models.items(), key=lambda x: roc_auc_score(y_test, x[1]))
best_auc = roc_auc_score(y_test, best_model[1])
print(f"最高性能: {best_model[0]} (AUC = {best_auc:.4f})")