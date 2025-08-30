import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats
from sklearn.metrics import classification_report
from sklearn.preprocessing import LabelEncoder

# Load data
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = df_raw.copy()

# Data preparation
df['Churn_Binary'] = (df['Churn'] == 'Yes').astype(int)
contract_mapping = {'Month-to-month': 0, 'One year': 1, 'Two year': 2}
df['Contract_Numeric'] = df['Contract'].map(contract_mapping)

print("=== Correlation Analysis: Churn vs Monthly Charges & Contract Type ===\n")

# Basic correlation coefficients
corr_charges_churn = df['MonthlyCharges'].corr(df['Churn_Binary'])
corr_contract_churn = df['Contract_Numeric'].corr(df['Churn_Binary'])
corr_charges_contract = df['MonthlyCharges'].corr(df['Contract_Numeric'])

print(f"Basic correlation coefficients:")
print(f"Monthly Charges ↔ Churn: {corr_charges_churn:.4f}")
print(f"Contract Type ↔ Churn: {corr_contract_churn:.4f}")
print(f"Monthly Charges ↔ Contract Type: {corr_charges_contract:.4f}")

# Statistical significance test
from scipy.stats import pearsonr
stat1, p1 = pearsonr(df['MonthlyCharges'], df['Churn_Binary'])
stat2, p2 = pearsonr(df['Contract_Numeric'], df['Churn_Binary'])
print(f"\nSignificance test (p-value):")
print(f"Monthly Charges ↔ Churn: {p1:.6f}")
print(f"Contract Type ↔ Churn: {p2:.6f}")

# Detailed churn rate analysis
print(f"\n=== Detailed Churn Rate Analysis ===")

# Churn rate by contract type
contract_churn = df.groupby('Contract').agg({
    'Churn_Binary': ['count', 'sum', 'mean'],
    'MonthlyCharges': 'mean'
}).round(3)
contract_churn.columns = ['Total', 'Churned', 'Churn_Rate', 'Avg_Charges']
print(f"\nChurn rate by contract type:")
print(contract_churn)

# 料金レベル別解約率
charge_quintiles = pd.qcut(df['MonthlyCharges'], q=5, labels=['Q1(最安)', 'Q2', 'Q3', 'Q4', 'Q5(最高)'])
df['Charge_Quintile'] = charge_quintiles

quintile_churn = df.groupby('Charge_Quintile').agg({
    'Churn_Binary': ['count', 'sum', 'mean'],
    'MonthlyCharges': ['min', 'max', 'mean']
}).round(3)
quintile_churn.columns = ['Total', 'Churned', 'Churn_Rate', 'Min_Charge', 'Max_Charge', 'Avg_Charge']
print(f"\n料金五分位別解約率:")
print(quintile_churn)

# 可視化
fig, axes = plt.subplots(3, 3, figsize=(18, 15))
fig.suptitle('Churn Correlation Analysis: Monthly Charges & Contract Type', fontsize=16, fontweight='bold')

# 1. 相関係数の比較
ax1 = axes[0, 0]
variables = ['Monthly Charges', 'Contract Type']
correlations = [corr_charges_churn, corr_contract_churn]
colors = ['blue' if x > 0 else 'red' for x in correlations]

bars = ax1.bar(variables, [abs(x) for x in correlations], color=colors, alpha=0.7)
ax1.set_title('1. Correlation with Churn', fontweight='bold')
ax1.set_ylabel('Correlation Coefficient (Absolute)')
ax1.set_ylim(0, max([abs(x) for x in correlations]) * 1.2)

for bar, corr in zip(bars, correlations):
    ax1.text(bar.get_x() + bar.get_width()/2., abs(corr) + 0.01,
             f'{corr:.3f}', ha='center', va='bottom', fontweight='bold')

# 2. 月額料金と解約の散布図
ax2 = axes[0, 1]
churned = df[df['Churn_Binary'] == 1]
retained = df[df['Churn_Binary'] == 0]

ax2.scatter(retained['MonthlyCharges'], np.random.normal(0, 0.02, len(retained)),
           alpha=0.6, label=f'Retained (n={len(retained)})', color='green', s=10)
ax2.scatter(churned['MonthlyCharges'], np.random.normal(1, 0.02, len(churned)),
           alpha=0.6, label=f'Churned (n={len(churned)})', color='red', s=10)

ax2.set_title(f'2. Monthly Charges vs Churn\n(Correlation: {corr_charges_churn:.3f})', fontweight='bold')
ax2.set_xlabel('Monthly Charges ($)')
ax2.set_ylabel('Churn (0:Retained, 1:Churned)')
ax2.set_yticks([0, 1])
ax2.set_yticklabels(['Retained', 'Churned'])
ax2.legend()
ax2.grid(True, alpha=0.3)

# 3. 契約タイプと解約の関係
ax3 = axes[0, 2]
contract_churn_rate = df.groupby('Contract')['Churn_Binary'].mean()
bars = ax3.bar(contract_churn_rate.index, contract_churn_rate.values, 
               color=['red', 'orange', 'green'], alpha=0.7)
ax3.set_title(f'3. Churn Rate by Contract Type\n(Correlation: {corr_contract_churn:.3f})', fontweight='bold')
ax3.set_ylabel('Churn Rate')
ax3.set_xlabel('Contract Type')

for bar, rate in zip(bars, contract_churn_rate.values):
    ax3.text(bar.get_x() + bar.get_width()/2., rate + 0.01,
             f'{rate:.1%}', ha='center', va='bottom', fontweight='bold')

plt.setp(ax3.xaxis.get_majorticklabels(), rotation=45)

# 4. 料金分布の比較（解約者 vs 継続者）
ax4 = axes[1, 0]
ax4.hist(retained['MonthlyCharges'], bins=30, alpha=0.7, label='Retained', color='green', density=True)
ax4.hist(churned['MonthlyCharges'], bins=30, alpha=0.7, label='Churned', color='red', density=True)
ax4.set_title('4. Charge Distribution Comparison', fontweight='bold')
ax4.set_xlabel('Monthly Charges ($)')
ax4.set_ylabel('Density')
ax4.legend()
ax4.grid(True, alpha=0.3)

# 5. Churn rate by charge quintile
ax5 = axes[1, 1]
quintile_rates = df.groupby('Charge_Quintile')['Churn_Binary'].mean()
bars = ax5.bar(range(len(quintile_rates)), quintile_rates.values, 
               color=['lightblue', 'skyblue', 'gold', 'orange', 'red'], alpha=0.7)
ax5.set_title('5. Churn Rate by Charge Quintile', fontweight='bold')
ax5.set_ylabel('Churn Rate')
ax5.set_xlabel('Charge Quintile')
ax5.set_xticks(range(len(quintile_rates)))
ax5.set_xticklabels(quintile_rates.index, rotation=45)

for bar, rate in zip(bars, quintile_rates.values):
    ax5.text(bar.get_x() + bar.get_width()/2., rate + 0.01,
             f'{rate:.1%}', ha='center', va='bottom', fontweight='bold')

# 6. Heatmap: Contract type × charge level × churn rate
ax6 = axes[1, 2]
charge_levels = pd.cut(df['MonthlyCharges'], bins=[0, 35, 55, 75, 120], 
                      labels=['Low', 'Med-Low', 'Med-High', 'High'])
df['Charge_Level'] = charge_levels

heatmap_data = df.pivot_table(values='Churn_Binary', 
                             index='Contract', 
                             columns='Charge_Level', 
                             aggfunc='mean')
sns.heatmap(heatmap_data, annot=True, fmt='.2f', cmap='YlOrRd', ax=ax6)
ax6.set_title('6. Churn Rate Heatmap\n(Contract × Charge Level)', fontweight='bold')

# 7. Box plot: Charge comparison between churned and retained
ax7 = axes[2, 0]
box_data = [retained['MonthlyCharges'], churned['MonthlyCharges']]
bp = ax7.boxplot(box_data, labels=['Retained', 'Churned'], patch_artist=True)
bp['boxes'][0].set_facecolor('green')
bp['boxes'][1].set_facecolor('red')
bp['boxes'][0].set_alpha(0.7)
bp['boxes'][1].set_alpha(0.7)

ax7.set_title('7. Charge Distribution Box Plot', fontweight='bold')
ax7.set_ylabel('Monthly Charges ($)')
ax7.grid(True, alpha=0.3)

# Add statistical information
retained_mean = retained['MonthlyCharges'].mean()
churned_mean = churned['MonthlyCharges'].mean()
ax7.text(0.5, 0.95, f'Retained avg: ${retained_mean:.2f}\nChurned avg: ${churned_mean:.2f}\nDifference: ${churned_mean - retained_mean:.2f}', 
         transform=ax7.transAxes, ha='left', va='top', fontsize=10,
         bbox=dict(boxstyle="round,pad=0.3", facecolor="white", alpha=0.8))

# 8. Logistic regression curve
ax8 = axes[2, 1]
from sklearn.linear_model import LogisticRegression

# Logistic regression
log_reg = LogisticRegression()
X = df['MonthlyCharges'].values.reshape(-1, 1)
y = df['Churn_Binary'].values
log_reg.fit(X, y)

# Prediction curve
X_range = np.linspace(df['MonthlyCharges'].min(), df['MonthlyCharges'].max(), 300).reshape(-1, 1)
y_prob = log_reg.predict_proba(X_range)[:, 1]

ax8.plot(X_range, y_prob, color='blue', linewidth=3, label='Logistic Regression')
ax8.scatter(df['MonthlyCharges'], df['Churn_Binary'], alpha=0.3, color='gray', s=10)

ax8.set_title('8. Logistic Regression Curve', fontweight='bold')
ax8.set_xlabel('Monthly Charges ($)')
ax8.set_ylabel('Churn Probability')
ax8.legend()
ax8.grid(True, alpha=0.3)

# 9. Correlation strength comparison
ax9 = axes[2, 2]

# Additional correlation analysis
df['TotalCharges_Numeric'] = pd.to_numeric(df['TotalCharges'], errors='coerce')
additional_corrs = {
    'tenure': df['tenure'].corr(df['Churn_Binary']),
    'TotalCharges': df['TotalCharges_Numeric'].corr(df['Churn_Binary'])
}

all_correlations = {
    'Monthly Charges': corr_charges_churn,
    'Contract Type': corr_contract_churn,
    'Tenure': additional_corrs['tenure'],
    'Total Charges': additional_corrs['TotalCharges']
}

variables = list(all_correlations.keys())
corr_values = list(all_correlations.values())
colors = ['blue' if x > 0 else 'red' for x in corr_values]

bars = ax9.barh(variables, [abs(x) for x in corr_values], color=colors, alpha=0.7)
ax9.set_title('9. Correlation Coefficient Comparison with Churn', fontweight='bold')
ax9.set_xlabel('Correlation Coefficient (Absolute Value)')

for bar, corr in zip(bars, corr_values):
    ax9.text(abs(corr) + 0.01, bar.get_y() + bar.get_height()/2.,
             f'{corr:.3f}', ha='left', va='center', fontweight='bold')

plt.tight_layout()
plt.show()

# Statistical tests
print(f"\n=== Statistical Test Results ===")

# t-test: Charge difference between churned and retained
t_stat, p_value = stats.ttest_ind(churned['MonthlyCharges'], retained['MonthlyCharges'])
print(f"\nt-test (charge difference):")
print(f"Statistic: {t_stat:.3f}, p-value: {p_value:.6f}")
print(f"Churned average: ${churned['MonthlyCharges'].mean():.2f}")
print(f"Retained average: ${retained['MonthlyCharges'].mean():.2f}")
print(f"Difference: ${churned['MonthlyCharges'].mean() - retained['MonthlyCharges'].mean():.2f}")

# Chi-square test: Contract type and churn
contingency = pd.crosstab(df['Contract'], df['Churn'])
chi2, p_chi2, dof, expected = stats.chi2_contingency(contingency)
print(f"\nChi-square test (contract type and churn):")
print(f"Chi-square statistic: {chi2:.3f}, p-value: {p_chi2:.6f}")

# 効果量の計算
# Cohen's d for charges
pooled_std = np.sqrt(((len(churned)-1)*churned['MonthlyCharges'].var() + 
                     (len(retained)-1)*retained['MonthlyCharges'].var()) / 
                    (len(churned) + len(retained) - 2))
cohens_d = (churned['MonthlyCharges'].mean() - retained['MonthlyCharges'].mean()) / pooled_std

print(f"\n効果量:")
print(f"Cohen's d (料金差): {cohens_d:.3f}")

# Cramer's V for contract
n = len(df)
cramers_v = np.sqrt(chi2 / (n * (min(contingency.shape) - 1)))
print(f"Cramer's V (contract type): {cramers_v:.3f}")

print(f"\n=== Practical Interpretation ===")
print(f"1. Relationship between charges and churn:")
if corr_charges_churn > 0.3:
    print("   Strong positive correlation - higher charges increase churn probability")
elif corr_charges_churn > 0.1:
    print("   Weak positive correlation - higher charges tend to increase churn")
else:
    print("   Correlation is weak")

print(f"2. Relationship between contract type and churn:")
if abs(corr_contract_churn) > 0.3:
    print("   Strong negative correlation - longer contracts reduce churn")
elif abs(corr_contract_churn) > 0.1:
    print("   Moderate negative correlation - longer contracts tend to reduce churn")
else:
    print("   Correlation is weak")

print(f"3. Segment with highest churn risk:")
max_risk = heatmap_data.max().max()
max_position = heatmap_data.stack().idxmax()
print(f"   {max_position[0]} × {max_position[1]}: Churn rate {max_risk:.1%}")

print(f"4. Importance for prediction:")
if abs(corr_contract_churn) > abs(corr_charges_churn):
    print("   Contract type is more important for churn prediction")
else:
    print("   Monthly charges are more important for churn prediction")