import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats
from scipy.stats import chi2_contingency

# Load data
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = df_raw.copy()

print("=== Correlation Analysis: Monthly Charges vs Contract Type ===\n")

# Numerical conversion
contract_mapping = {'Month-to-month': 0, 'One year': 1, 'Two year': 2}
df['Contract_Numeric'] = df['Contract'].map(contract_mapping)

# Basic statistics
correlation = df['Contract_Numeric'].corr(df['MonthlyCharges'])
print(f"Correlation coefficient: {correlation:.4f}")

# Statistical significance test
stat, p_value = stats.spearmanr(df['Contract_Numeric'], df['MonthlyCharges'])
print(f"Spearman correlation: {stat:.4f} (p-value: {p_value:.6f})")

# Monthly charges statistics by contract type
print(f"\nMonthly charges statistics by contract type:")
charges_stats = df.groupby('Contract')['MonthlyCharges'].agg([
    'count', 'mean', 'median', 'std', 'min', 'max'
]).round(2)
print(charges_stats)

# ANOVA test
contract_groups = [df[df['Contract'] == contract]['MonthlyCharges'].values 
                  for contract in df['Contract'].unique()]
f_stat, p_anova = stats.f_oneway(*contract_groups)
print(f"\nANOVA test: F={f_stat:.3f}, p-value={p_anova:.6f}")

# Visualization
fig, axes = plt.subplots(3, 3, figsize=(18, 15))
fig.suptitle('Correlation Analysis: Monthly Charges vs Contract Type', fontsize=16, fontweight='bold')

# 1. Scatter plot
ax1 = axes[0, 0]
colors = {'Month-to-month': 'red', 'One year': 'orange', 'Two year': 'green'}
for contract in df['Contract'].unique():
    subset = df[df['Contract'] == contract]
    ax1.scatter(subset['Contract_Numeric'], subset['MonthlyCharges'], 
               alpha=0.6, label=contract, color=colors[contract], s=20)

# Regression line
z = np.polyfit(df['Contract_Numeric'], df['MonthlyCharges'], 1)
p = np.poly1d(z)
ax1.plot(df['Contract_Numeric'].unique(), p(df['Contract_Numeric'].unique()), 
         "r--", alpha=0.8, linewidth=2)

ax1.set_title(f'1. Scatter Plot\n(Correlation: {correlation:.3f})', fontweight='bold')
ax1.set_xlabel('Contract Type (0:Month-to-month, 1:One year, 2:Two year)')
ax1.set_ylabel('Monthly Charges ($)')
ax1.legend()
ax1.grid(True, alpha=0.3)

# 2. Box plot
ax2 = axes[0, 1]
df.boxplot(column='MonthlyCharges', by='Contract', ax=ax2)
ax2.set_title('2. Monthly Charges by Contract Type')
ax2.set_xlabel('Contract Type')
ax2.set_ylabel('Monthly Charges ($)')

# 3. Violin plot
ax3 = axes[0, 2]
sns.violinplot(data=df, x='Contract', y='MonthlyCharges', ax=ax3)
ax3.set_title('3. Monthly Charges Distribution\n(Density Plot)', fontweight='bold')
ax3.set_xlabel('Contract Type')
ax3.set_ylabel('Monthly Charges ($)')
plt.setp(ax3.xaxis.get_majorticklabels(), rotation=45)

# 4. Bar chart of average charges
ax4 = axes[1, 0]
mean_charges = df.groupby('Contract')['MonthlyCharges'].mean()
bars = ax4.bar(mean_charges.index, mean_charges.values, 
               color=['red', 'orange', 'green'], alpha=0.7)
ax4.set_title('4. Average Monthly Charges by Contract', fontweight='bold')
ax4.set_ylabel('Average Monthly Charges ($)')
ax4.set_xlabel('Contract Type')

# Display values on bars
for bar, value in zip(bars, mean_charges.values):
    ax4.text(bar.get_x() + bar.get_width()/2., value + 1,
             f'${value:.2f}', ha='center', va='bottom', fontweight='bold')

plt.setp(ax4.xaxis.get_majorticklabels(), rotation=45)

# 5. Histogram (overlapped)
ax5 = axes[1, 1]
for contract in df['Contract'].unique():
    subset = df[df['Contract'] == contract]
    ax5.hist(subset['MonthlyCharges'], bins=30, alpha=0.6, 
             label=f'{contract} (n={len(subset)})', color=colors[contract])

ax5.set_title('5. Charge Distribution by Contract\n(Histogram)', fontweight='bold')
ax5.set_xlabel('Monthly Charges ($)')
ax5.set_ylabel('Number of Customers')
ax5.legend()
ax5.grid(True, alpha=0.3)

# 6. Cumulative distribution function
ax6 = axes[1, 2]
for contract in df['Contract'].unique():
    subset = df[df['Contract'] == contract]
    sorted_charges = np.sort(subset['MonthlyCharges'])
    cumulative = np.arange(1, len(sorted_charges) + 1) / len(sorted_charges)
    ax6.plot(sorted_charges, cumulative, label=contract, 
             color=colors[contract], linewidth=2)

ax6.set_title('6. Cumulative Distribution Function', fontweight='bold')
ax6.set_xlabel('Monthly Charges ($)')
ax6.set_ylabel('Cumulative Probability')
ax6.legend()
ax6.grid(True, alpha=0.3)

# 7. Contract type distribution by charge range
ax7 = axes[2, 0]
charge_bins = [0, 30, 50, 70, 90, 120]
charge_labels = ['<$30', '$30-50', '$50-70', '$70-90', '>$90']
df['Charge_Range'] = pd.cut(df['MonthlyCharges'], bins=charge_bins, labels=charge_labels)

range_contract = pd.crosstab(df['Charge_Range'], df['Contract'], normalize='index') * 100
range_contract.plot(kind='bar', ax=ax7, color=['red', 'orange', 'green'], alpha=0.7)
ax7.set_title('7. Contract Type Composition by Charge Range', fontweight='bold')
ax7.set_xlabel('Monthly Charge Range')
ax7.set_ylabel('Composition (%)')
ax7.legend(title='Contract Type')
plt.setp(ax7.xaxis.get_majorticklabels(), rotation=45)

# 8. Correlation matrix heatmap
ax8 = axes[2, 1]
# Correlation matrix including additional variables
df['TotalCharges_Numeric'] = pd.to_numeric(df['TotalCharges'], errors='coerce')
corr_vars = ['Contract_Numeric', 'MonthlyCharges', 'tenure', 'TotalCharges_Numeric']
corr_matrix = df[corr_vars].corr()

sns.heatmap(corr_matrix, annot=True, fmt='.3f', cmap='RdBu_r', center=0, ax=ax8)
ax8.set_title('8. Correlation Matrix', fontweight='bold')

# 9. Regression analysis results
ax9 = axes[2, 2]
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score

# Simple regression
reg = LinearRegression()
X = df['Contract_Numeric'].values.reshape(-1, 1)
y = df['MonthlyCharges'].values
reg.fit(X, y)
y_pred = reg.predict(X)
r2 = r2_score(y, y_pred)

# Residual plot
residuals = y - y_pred
ax9.scatter(y_pred, residuals, alpha=0.6, color='blue')
ax9.axhline(y=0, color='red', linestyle='--', alpha=0.8)
ax9.set_title(f'9. Residual Plot\n(R² = {r2:.3f})', fontweight='bold')
ax9.set_xlabel('Predicted Value ($)')
ax9.set_ylabel('Residual ($)')
ax9.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# Detailed analysis
print(f"\n=== Detailed Analysis Results ===")

print(f"\n1. Correlation strength:")
if abs(correlation) < 0.1:
    strength = "very weak"
elif abs(correlation) < 0.3:
    strength = "weak"
elif abs(correlation) < 0.5:
    strength = "moderate"
elif abs(correlation) < 0.7:
    strength = "strong"
else:
    strength = "very strong"
print(f"   Correlation coefficient {correlation:.3f} indicates {strength} correlation")

print(f"\n2. Charge differences between contract types:")
contracts = ['Month-to-month', 'One year', 'Two year']
for i in range(len(contracts)):
    for j in range(i+1, len(contracts)):
        group1 = df[df['Contract'] == contracts[i]]['MonthlyCharges']
        group2 = df[df['Contract'] == contracts[j]]['MonthlyCharges']
        t_stat, p_val = stats.ttest_ind(group1, group2)
        diff = group1.mean() - group2.mean()
        print(f"   {contracts[i]} vs {contracts[j]}: difference ${diff:.2f} (p={p_val:.4f})")

print(f"\n3. Variance analysis of charges:")
total_var = df['MonthlyCharges'].var()
within_var = sum([df[df['Contract'] == contract]['MonthlyCharges'].var() * 
                  (len(df[df['Contract'] == contract]) - 1) 
                  for contract in contracts]) / (len(df) - len(contracts))
between_var = total_var - within_var
explained_var_ratio = between_var / total_var

print(f"   Proportion of charge variance explained by contract type: {explained_var_ratio:.1%}")

print(f"\n4. Practical interpretation:")
print(f"   - Longer contracts tend to have lower average charges")
print(f"   - However, the correlation is {strength}, with large individual differences")
print(f"   - Contract type alone can only explain {explained_var_ratio:.1%} of charge variance")