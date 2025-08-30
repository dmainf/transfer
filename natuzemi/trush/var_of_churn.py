import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from lib.prepro import clean_data

# Data loading and preprocessing
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = clean_data(df_raw.copy())
df = df.drop(columns=['CustomerID'])

# Keep original data for visualization
df_original = df_raw.copy()
df_original['Churn'] = df_original['Churn'].apply(lambda x: 1 if x == 'Yes' else 0)

# Churn correlation analysis
print("=== Churn Correlation Analysis ===")
# Correlation with numerical columns
numeric_cols = df.select_dtypes(include=[np.number]).columns.tolist()
numeric_cols.remove('Churn')  # Remove Churn itself
correlations = df[numeric_cols + ['Churn']].corr()['Churn'].abs().sort_values(ascending=False)
print("Correlation between numerical columns and Churn:")
print(correlations)

# Categorical columns churn rate analysis
categorical_cols = df.select_dtypes(include=['object']).columns.tolist()
print("\n=== Categorical Columns Churn Rate Analysis ===")
churn_rates_by_category = {}

for col in categorical_cols:
    churn_rate = df.groupby(col)['Churn'].mean().sort_values(ascending=False)
    print(f"\nChurn rate by {col}:")
    print(churn_rate)
    # Calculate difference between max and min churn rates (as impact indicator)
    impact = churn_rate.max() - churn_rate.min()
    churn_rates_by_category[col] = impact
    print(f"Impact (max-min): {impact:.3f}")

# Sort categorical variables by impact
sorted_categorical = sorted(churn_rates_by_category.items(), key=lambda x: x[1], reverse=True)
print("\n=== Categorical Variables Impact Ranking ===")
for col, impact in sorted_categorical:
    print(f"{col}: {impact:.3f}")

# Identify top 3 important variables
print("\n=== Top 3 Columns Most Related to Churn ===")
top_numeric = correlations.head(4)
top_categorical = sorted_categorical[:4]

print("Numerical variables (correlation coefficient):")
for col in top_numeric.index:
    print(f"  {col}: {correlations[col]:.3f}")

print("\nCategorical variables (impact):")
for col, impact in top_categorical:
    print(f"  {col}: {impact:.3f}")

# Select 3 most important columns overall
# Contract, tenure, MonthlyCharges seem important
important_cols = ['Contract', 'tenure', 'MonthlyCharges']

print(f"\n=== Selected 3 Most Important Columns: {important_cols} ===")

# Detailed analysis and visualization for each column
plt.figure(figsize=(15, 5))

# 1. Churn rate by Contract (using original data)
plt.subplot(1, 3, 1)
contract_churn = df_original.groupby('Contract')['Churn'].agg(['mean', 'count'])
contract_churn['mean'].plot(kind='bar')
plt.title('Churn Rate by Contract')
plt.ylabel('Churn Rate')
plt.xlabel('Contract')
plt.xticks(rotation=45)
for i, (idx, row) in enumerate(contract_churn.iterrows()):
    plt.text(i, row['mean'] + 0.01, f'{row["mean"]:.1%}\n(n={row["count"]})', 
             ha='center', va='bottom')

# 2. Relationship between tenure and churn rate
plt.subplot(1, 3, 2)
# Divide tenure into intervals
df_original['tenure_group'] = pd.cut(df_original['tenure'], 
                           bins=[0, 12, 24, 36, 48, 100], 
                           labels=['0-12M', '13-24M', '25-36M', '37-48M', '49M+'])
tenure_churn = df_original.groupby('tenure_group')['Churn'].agg(['mean', 'count'])
tenure_churn['mean'].plot(kind='bar')
plt.title('Churn Rate by Tenure')
plt.ylabel('Churn Rate')
plt.xlabel('Tenure (months)')
plt.xticks(rotation=45)
for i, (idx, row) in enumerate(tenure_churn.iterrows()):
    plt.text(i, row['mean'] + 0.01, f'{row["mean"]:.1%}\n(n={row["count"]})', 
             ha='center', va='bottom')

# 3. Relationship between MonthlyCharges and churn rate
plt.subplot(1, 3, 3)
# Divide MonthlyCharges into intervals
df_original['charges_group'] = pd.cut(df_original['MonthlyCharges'], 
                            bins=[0, 35, 55, 75, 120], 
                            labels=['Low\n(~35)', 'Mid-Low\n(35-55)', 'Mid-High\n(55-75)', 'High\n(75~)'])
charges_churn = df_original.groupby('charges_group')['Churn'].agg(['mean', 'count'])
charges_churn['mean'].plot(kind='bar')
plt.title('Churn Rate by Monthly Charges')
plt.ylabel('Churn Rate')
plt.xlabel('Monthly Charges Range')
plt.xticks(rotation=0)
for i, (idx, row) in enumerate(charges_churn.iterrows()):
    plt.text(i, row['mean'] + 0.01, f'{row["mean"]:.1%}\n(n={row["count"]})', 
             ha='center', va='bottom')

plt.tight_layout()
plt.show()

# Display detailed statistical information
print("\n=== Detailed Analysis Results ===")
print("\n1. Churn Rate by Contract:")
contract_stats = df_original.groupby('Contract')['Churn'].agg(['mean', 'count', 'sum'])
contract_stats.columns = ['Churn_Rate', 'Customer_Count', 'Churned_Count']
contract_stats['Churn_Rate'] = contract_stats['Churn_Rate'].apply(lambda x: f'{x:.1%}')
print(contract_stats)

print("\n2. Churn Rate by Tenure:")
tenure_stats = df_original.groupby('tenure_group')['Churn'].agg(['mean', 'count', 'sum'])
tenure_stats.columns = ['Churn_Rate', 'Customer_Count', 'Churned_Count']
tenure_stats['Churn_Rate'] = tenure_stats['Churn_Rate'].apply(lambda x: f'{x:.1%}')
print(tenure_stats)

print("\n3. Churn Rate by Monthly Charges:")
charges_stats = df_original.groupby('charges_group')['Churn'].agg(['mean', 'count', 'sum'])
charges_stats.columns = ['Churn_Rate', 'Customer_Count', 'Churned_Count']
charges_stats['Churn_Rate'] = charges_stats['Churn_Rate'].apply(lambda x: f'{x:.1%}')
print(charges_stats)