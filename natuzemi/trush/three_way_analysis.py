import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats

# Load data
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = df_raw.copy()
df['Churn_Binary'] = (df['Churn'] == 'Yes').astype(int)

print("=== 3-Way Relationship Analysis: Contract Type × Monthly Charges × Churn ===\n")

# 1. Basic correlations
print("=== 1. Basic Correlations ===")
# Create numeric version of Contract
contract_mapping = {'Month-to-month': 0, 'One year': 1, 'Two year': 2}
df['Contract_Numeric'] = df['Contract'].map(contract_mapping)

corr_contract_churn = df['Contract_Numeric'].corr(df['Churn_Binary'])
corr_charges_churn = df['MonthlyCharges'].corr(df['Churn_Binary'])
corr_contract_charges = df['Contract_Numeric'].corr(df['MonthlyCharges'])

print(f"Contract Type ↔ Churn: {corr_contract_churn:.3f}")
print(f"Monthly Charges ↔ Churn: {corr_charges_churn:.3f}")
print(f"Contract Type ↔ Monthly Charges: {corr_contract_charges:.3f}")

# 2. Detailed breakdown by contract type
print("\n=== 2. Monthly Charges by Contract Type ===")
charges_by_contract = df.groupby('Contract')['MonthlyCharges'].agg([
    'mean', 'median', 'std', 'min', 'max', 'count'
]).round(2)
print(charges_by_contract)

# 3. Churn rates by contract and charge segments
print("\n=== 3. Churn Rate by Contract Type ===")
churn_by_contract = df.groupby('Contract').agg({
    'Churn_Binary': ['mean', 'count', 'sum'],
    'MonthlyCharges': 'mean'
}).round(3)
churn_by_contract.columns = ['Churn_Rate', 'Total_Customers', 'Churned_Count', 'Avg_Charges']
print(churn_by_contract)

# 4. Create charge bins for detailed analysis
print("\n=== 4. Three-way Analysis: Contract × Charge Level × Churn ===")
df['Charge_Level'] = pd.cut(df['MonthlyCharges'], 
                           bins=[0, 30, 50, 70, 90, 120], 
                           labels=['Very Low\n(<$30)', 'Low\n($30-50)', 'Medium\n($50-70)', 
                                  'High\n($70-90)', 'Very High\n(>$90)'])

# Three-way crosstab
three_way = df.groupby(['Contract', 'Charge_Level']).agg({
    'Churn_Binary': ['mean', 'count', 'sum']
}).round(3)
three_way.columns = ['Churn_Rate', 'Customer_Count', 'Churned_Count']

print("\nChurn Rate by Contract Type and Charge Level:")
print(three_way)

# 5. Statistical significance tests
print("\n=== 5. Statistical Tests ===")
from scipy.stats import chi2_contingency

# Chi-square test for Contract vs Churn
contingency_contract = pd.crosstab(df['Contract'], df['Churn'])
chi2_contract, p_contract, _, _ = chi2_contingency(contingency_contract)
print(f"Contract vs Churn - Chi-square: {chi2_contract:.3f}, p-value: {p_contract:.6f}")

# ANOVA for Monthly Charges across Contract Types
contract_groups = [df[df['Contract'] == contract]['MonthlyCharges'].values 
                  for contract in df['Contract'].unique()]
f_stat, p_anova = stats.f_oneway(*contract_groups)
print(f"Monthly Charges across Contracts - F-statistic: {f_stat:.3f}, p-value: {p_anova:.6f}")

# 6. Visualizations
fig, axes = plt.subplots(2, 2, figsize=(15, 12))

# Plot 1: Monthly Charges by Contract Type (Box Plot)
ax1 = axes[0, 0]
df.boxplot(column='MonthlyCharges', by='Contract', ax=ax1)
ax1.set_title('Monthly Charges Distribution by Contract Type')
ax1.set_xlabel('Contract Type')
ax1.set_ylabel('Monthly Charges ($)')

# Plot 2: Churn Rate by Contract Type
ax2 = axes[0, 1]
churn_rates = df.groupby('Contract')['Churn_Binary'].mean()
bars = ax2.bar(churn_rates.index, churn_rates.values)
ax2.set_title('Churn Rate by Contract Type')
ax2.set_ylabel('Churn Rate')
ax2.set_xlabel('Contract Type')
plt.setp(ax2.xaxis.get_majorticklabels(), rotation=45)

# Add percentage labels on bars
for i, bar in enumerate(bars):
    height = bar.get_height()
    ax2.text(bar.get_x() + bar.get_width()/2., height + 0.01,
             f'{height:.1%}', ha='center', va='bottom')

# Plot 3: Heatmap of Churn Rate by Contract and Charge Level
ax3 = axes[1, 0]
pivot_heatmap = df.pivot_table(values='Churn_Binary', 
                              index='Contract', 
                              columns='Charge_Level', 
                              aggfunc='mean')
sns.heatmap(pivot_heatmap, annot=True, fmt='.2f', cmap='YlOrRd', ax=ax3)
ax3.set_title('Churn Rate Heatmap\n(Contract × Charge Level)')

# Plot 4: Scatter plot with Contract Type coloring
ax4 = axes[1, 1]
colors = {'Month-to-month': 'red', 'One year': 'orange', 'Two year': 'green'}
for contract in df['Contract'].unique():
    subset = df[df['Contract'] == contract]
    ax4.scatter(subset['MonthlyCharges'], subset['Churn_Binary'], 
               alpha=0.6, label=contract, color=colors[contract])

ax4.set_xlabel('Monthly Charges ($)')
ax4.set_ylabel('Churn (0=No, 1=Yes)')
ax4.set_title('Monthly Charges vs Churn by Contract Type')
ax4.legend()
ax4.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# 7. Key insights summary
print("\n" + "="*50)
print("KEY INSIGHTS SUMMARY")
print("="*50)

# Find highest risk segments
high_risk = three_way[three_way['Churn_Rate'] > 0.4]
if not high_risk.empty:
    print("Highest Risk Segments (Churn Rate > 40%):")
    for (contract, charge_level), row in high_risk.iterrows():
        print(f"  {contract} + {charge_level}: {row['Churn_Rate']:.1%} "
              f"({row['Customer_Count']} customers)")

# Find lowest risk segments  
low_risk = three_way[three_way['Churn_Rate'] < 0.1]
if not low_risk.empty:
    print("\nLowest Risk Segments (Churn Rate < 10%):")
    for (contract, charge_level), row in low_risk.iterrows():
        print(f"  {contract} + {charge_level}: {row['Churn_Rate']:.1%} "
              f"({row['Customer_Count']} customers)")

# Average charges by contract
print(f"\nAverage Monthly Charges by Contract:")
for contract in df['Contract'].unique():
    avg_charge = df[df['Contract'] == contract]['MonthlyCharges'].mean()
    churn_rate = df[df['Contract'] == contract]['Churn_Binary'].mean()
    print(f"  {contract}: ${avg_charge:.2f} (Churn: {churn_rate:.1%})")

# Correlation interpretations
print(f"\nCorrelation Interpretations:")
print(f"1. Contract Type → Churn: {corr_contract_churn:.3f} (negative = longer contracts reduce churn)")
print(f"2. Monthly Charges → Churn: {corr_charges_churn:.3f} (positive = higher charges increase churn)")  
print(f"3. Contract Type → Charges: {corr_contract_charges:.3f} (negative = longer contracts have lower charges)")

print(f"\nParadox Resolution:")
print("- Longer contracts have LOWER average charges (due to discounts)")
print("- But within same contract type, HIGHER charges increase churn risk")
print("- Contract type effect dominates: 2-year contracts have lowest churn despite some high-charge customers")