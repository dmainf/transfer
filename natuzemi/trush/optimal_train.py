import pandas as pd
import numpy as np
from sklearn.utils import shuffle
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, roc_auc_score
from imblearn.over_sampling import SMOTE
from lib.prepro import clean_data, one_hot_encoding, merge_df

df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')

clean_df = shuffle(clean_data(df_raw.copy()), random_state=42).reset_index(drop=True)
categorical_vars = ['Gender','InternetServiceType','PaymentMethod','ContractType']
binary_vars = ['SeniorCitizen','Partner','Dependents','PhoneService','MultipleLines','OnlineSecurity','OnlineBackup'
               ,'DeviceProtection','TechSupport','StreamingTV', 'StreamingMovies','PaperlessBilling','InternetService'
               , 'IsContracted']
numeric_vars = ['Tenure','MonthlyCharges']
target_var = 'Churn'

clean_df_encoded = one_hot_encoding(clean_df, categorical_vars)
clean_df_encoded = clean_df_encoded.drop(['CustomerID', 'Contract', 'Churn'], axis=1)
feature_df = merge_df(clean_df_encoded, clean_df[binary_vars], clean_df[numeric_vars])
target_df = clean_df[target_var]
X = feature_df
y = target_df
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)
smote = SMOTE(random_state=42)
X_train_smote, y_train_smote = smote.fit_resample(X_train, y_train)

optimal_rf = RandomForestClassifier(
    n_estimators=100,
    max_depth=5,
    max_features=0.7,
    min_samples_leaf=5,
    oob_score=True,
    random_state=42
)
optimal_rf.fit(X_train_smote, y_train_smote)
y_pred = optimal_rf.predict(X_test)
y_pred_proba = optimal_rf.predict_proba(X_test)[:, 1]

print("=== 最適ハイパーパラメータでの学習結果 ===")
print(f"使用したパラメータ:")
print(f"- n_estimators: 100")
print(f"- max_depth: 5")
print(f"- max_features: 0.7")
print(f"- min_samples_leaf: 5")
print(f"- SMOTE適用: Yes")
print()
print(f"OOB Score: {optimal_rf.oob_score_:.4f}")
print(f"Test AUC ROC Score: {roc_auc_score(y_test, y_pred_proba):.4f}")
print()
print("Classification Report:")
print(classification_report(y_test, y_pred))

from sklearn.ensemble import GradientBoostingClassifier, VotingClassifier
gb_model = GradientBoostingClassifier(
    n_estimators=100,
    max_depth=5,
    learning_rate=0.1,
    random_state=42
)
# アンサンブル学習（RandomForest + GradientBoosting）
ensemble_model = VotingClassifier(
    estimators=[
        ('rf', optimal_rf),
        ('gb', gb_model)
    ],
    voting='soft'
)

ensemble_model.fit(X_train_smote, y_train_smote)
ensemble_pred = ensemble_model.predict(X_test)
ensemble_pred_proba = ensemble_model.predict_proba(X_test)[:, 1]

# 結果表示
print("=== アンサンブル学習結果 ===")
print(f"使用したアルゴリズム: RandomForest + GradientBoosting")
print(f"アンサンブル手法: Voting Classifier (soft)")
print(f"SMOTE適用: Yes")
print()

print(f"Test AUC ROC Score: {roc_auc_score(y_test, ensemble_pred_proba):.4f}")
print()

print("Classification Report:")
print(classification_report(y_test, ensemble_pred))