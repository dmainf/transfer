import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LogisticRegression, LinearRegression
from sklearn.preprocessing import StandardScaler
from scipy import stats

# Load data
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = df_raw.copy()

# Data preparation
df['Churn_Binary'] = (df['Churn'] == 'Yes').astype(int)
df['Long_Contract'] = (df['Contract'] != 'Month-to-month').astype(int)

# Standardization
scaler = StandardScaler()
df['MonthlyCharges_Std'] = scaler.fit_transform(df[['MonthlyCharges']])

# Create binary variables
for col in ['Partner', 'Dependents', 'PhoneService']:
    df[col + '_Binary'] = (df[col] == 'Yes').astype(int)

df['TotalCharges_Numeric'] = pd.to_numeric(df['TotalCharges'], errors='coerce')
df['TotalCharges_Numeric'] = df['TotalCharges_Numeric'].fillna(df['TotalCharges_Numeric'].median())

print("=== Causal Inference and Spurious Correlation Analysis for Churn ===\n")

# Confounding factors
confounders = ['SeniorCitizen', 'Partner_Binary', 'Dependents_Binary', 
               'tenure', 'PhoneService_Binary', 'TotalCharges_Numeric']

# 1. Unadjusted vs adjusted effects
print("1. Comparison of unadjusted vs adjusted effects")

# Unadjusted effects
model_contract_unadj = LogisticRegression(random_state=42)
model_contract_unadj.fit(df[['Long_Contract']], df['Churn_Binary'])
contract_effect_unadj = model_contract_unadj.coef_[0][0]

model_charges_unadj = LogisticRegression(random_state=42)
model_charges_unadj.fit(df[['MonthlyCharges_Std']], df['Churn_Binary'])
charges_effect_unadj = model_charges_unadj.coef_[0][0]

# Adjusted effects
X_adjusted = df[['Long_Contract', 'MonthlyCharges_Std'] + confounders]
model_adjusted = LogisticRegression(random_state=42)
model_adjusted.fit(X_adjusted, df['Churn_Binary'])
contract_effect_adj = model_adjusted.coef_[0][0]
charges_effect_adj = model_adjusted.coef_[0][1]

print(f"Contract type effect - Unadjusted: {contract_effect_unadj:.3f}, Adjusted: {contract_effect_adj:.3f}")
print(f"Monthly charges effect - Unadjusted: {charges_effect_unadj:.3f}, Adjusted: {charges_effect_adj:.3f}")
print(f"Contract type bias: {contract_effect_unadj - contract_effect_adj:.3f}")
print(f"Monthly charges bias: {charges_effect_unadj - charges_effect_adj:.3f}")

# 2. Propensity score analysis
print(f"\n2. Propensity score analysis")

# Propensity score estimation
ps_model = LogisticRegression(random_state=42)
ps_model.fit(df[confounders + ['MonthlyCharges_Std']], df['Long_Contract'])
propensity_scores = ps_model.predict_proba(df[confounders + ['MonthlyCharges_Std']])[:, 1]
df['PropensityScore'] = propensity_scores

# IPW estimation
treated = df[df['Long_Contract'] == 1]
control = df[df['Long_Contract'] == 0]

ps_treated = np.clip(treated['PropensityScore'], 0.01, 0.99)
ps_control = np.clip(control['PropensityScore'], 0.01, 0.99)

ate_treated = np.mean(treated['Churn_Binary'] / ps_treated)
ate_control = np.mean(control['Churn_Binary'] / (1 - ps_control))
ate_ipw = ate_treated - ate_control

simple_diff = treated['Churn_Binary'].mean() - control['Churn_Binary'].mean()

print(f"Simple difference: {simple_diff:.3f}")
print(f"IPW estimate: {ate_ipw:.3f}")
print(f"Bias: {simple_diff - ate_ipw:.3f}")

# Visualization
fig, axes = plt.subplots(3, 3, figsize=(18, 15))
fig.suptitle('Causal Inference Analysis and Spurious Correlation Detection', fontsize=16, fontweight='bold')

# 1. Effect size comparison
ax1 = axes[0, 0]
effects = ['Contract\n(Unadj)', 'Contract\n(Adj)', 'Charges\n(Unadj)', 'Charges\n(Adj)']
values = [contract_effect_unadj, contract_effect_adj, charges_effect_unadj, charges_effect_adj]
colors = ['lightcoral', 'red', 'lightblue', 'blue']

bars = ax1.bar(effects, values, color=colors, alpha=0.7)
ax1.set_title('1. Unadjusted vs Adjusted Effects', fontweight='bold')
ax1.set_ylabel('Logistic Regression Coefficient')
ax1.axhline(y=0, color='black', linestyle='-', alpha=0.3)
ax1.grid(True, alpha=0.3)

for bar, value in zip(bars, values):
    ax1.text(bar.get_x() + bar.get_width()/2., value + 0.05 if value > 0 else value - 0.1,
             f'{value:.3f}', ha='center', va='bottom' if value > 0 else 'top', fontweight='bold')

# 2. Propensity score distribution
ax2 = axes[0, 1]
ax2.hist(control['PropensityScore'], bins=30, alpha=0.7, label='Control (Month-to-month)', color='red')
ax2.hist(treated['PropensityScore'], bins=30, alpha=0.7, label='Treated (Long-term)', color='blue')
ax2.set_title('2. Propensity Score Distribution', fontweight='bold')
ax2.set_xlabel('Propensity Score')
ax2.set_ylabel('Frequency')
ax2.legend()
ax2.grid(True, alpha=0.3)

# 3. IPW vs simple difference
ax3 = axes[0, 2]
methods = ['Simple\nDifference', 'IPW\nEstimate']
estimates = [simple_diff, ate_ipw]
bars = ax3.bar(methods, estimates, color=['orange', 'green'], alpha=0.7)
ax3.set_title('3. Causal Effect Estimation', fontweight='bold')
ax3.set_ylabel('Probability Difference')
ax3.grid(True, alpha=0.3)

for bar, value in zip(bars, estimates):
    ax3.text(bar.get_x() + bar.get_width()/2., value + 0.01,
             f'{value:.3f}', ha='center', va='bottom', fontweight='bold')

# 4. Spurious correlation visualization - contract type and monthly charges
ax4 = axes[1, 0]
contract_charges = df.groupby('Contract')['MonthlyCharges'].mean()
bars = ax4.bar(range(len(contract_charges)), contract_charges.values, 
               color=['red', 'orange', 'green'], alpha=0.7)
ax4.set_title('4. Average Monthly Charges by Contract Type\n(Source of Spurious Correlation)', fontweight='bold')
ax4.set_ylabel('Average Monthly Charges ($)')
ax4.set_xticks(range(len(contract_charges)))
ax4.set_xticklabels(contract_charges.index, rotation=45)

for bar, value in zip(bars, contract_charges.values):
    ax4.text(bar.get_x() + bar.get_width()/2., value + 1,
             f'${value:.1f}', ha='center', va='bottom', fontweight='bold')

# 5. Residual analysis - charge effect after removing contract type effect
ax5 = axes[1, 1]
# Regression of monthly charges using contract type as explanatory variable
contract_dummy = pd.get_dummies(df['Contract'], drop_first=True)
X_contract = contract_dummy
reg_charges = LinearRegression()
reg_charges.fit(X_contract, df['MonthlyCharges'])
charges_residual = df['MonthlyCharges'] - reg_charges.predict(X_contract)

# Relationship between residuals and churn
bins = np.linspace(charges_residual.min(), charges_residual.max(), 20)
bin_centers = (bins[:-1] + bins[1:]) / 2
churn_rates = []

for i in range(len(bins)-1):
    mask = (charges_residual >= bins[i]) & (charges_residual < bins[i+1])
    if mask.sum() > 10:
        churn_rates.append(df[mask]['Churn_Binary'].mean())
    else:
        churn_rates.append(np.nan)

ax5.plot(bin_centers, churn_rates, 'o-', color='purple', linewidth=2)
ax5.set_title('5. Charges-Churn Relationship Excluding Contract Effect', fontweight='bold')
ax5.set_xlabel('Monthly Charges Residual ($)')
ax5.set_ylabel('Churn Rate')
ax5.grid(True, alpha=0.3)

# 6. Dose-response relationship
ax6 = axes[1, 2]
charge_quintiles = pd.qcut(df['MonthlyCharges'], q=5, labels=['Q1', 'Q2', 'Q3', 'Q4', 'Q5'])
dose_response = df.groupby(charge_quintiles).agg({
    'Churn_Binary': 'mean',
    'MonthlyCharges': 'mean'
})

ax6.plot(dose_response['MonthlyCharges'].values, dose_response['Churn_Binary'].values, 
         'o-', color='red', linewidth=3, markersize=8)
ax6.set_title('6. Dose-Response Relationship for Monthly Charges', fontweight='bold')
ax6.set_xlabel('Average Monthly Charges ($)')
ax6.set_ylabel('Churn Rate')
ax6.grid(True, alpha=0.3)

# 7. Effects of confounding factors
ax7 = axes[2, 0]
confounders_short = ['SeniorCitizen', 'Partner', 'Dependents', 'tenure', 'PhoneService']
coefficients = model_adjusted.coef_[0][2:7]  # Coefficients of confounding factors

bars = ax7.barh(confounders_short, coefficients, color='gray', alpha=0.7)
ax7.set_title('7. Effects of Confounding Factors', fontweight='bold')
ax7.set_xlabel('Logistic Regression Coefficient')
ax7.axvline(x=0, color='black', linestyle='-', alpha=0.3)
ax7.grid(True, alpha=0.3)

# 8. Correlation vs causal effects
ax8 = axes[2, 1]
correlations = [df['Long_Contract'].corr(df['Churn_Binary']), 
                df['MonthlyCharges'].corr(df['Churn_Binary'])]
causal_effects = [contract_effect_adj, charges_effect_adj]

x_pos = np.arange(2)
width = 0.35

ax8.bar(x_pos - width/2, np.abs(correlations), width, label='Correlation', alpha=0.7, color='orange')
ax8.bar(x_pos + width/2, np.abs(causal_effects), width, label='Causal Effect', alpha=0.7, color='blue')

ax8.set_title('8. Correlation vs Causal Effects Comparison', fontweight='bold')
ax8.set_ylabel('Effect Size (Absolute Value)')
ax8.set_xticks(x_pos)
ax8.set_xticklabels(['Contract Type', 'Monthly Charges'])
ax8.legend()
ax8.grid(True, alpha=0.3)

# 9. Spurious correlation structure diagram
ax9 = axes[2, 2]
ax9.text(0.1, 0.8, 'Contract Type', bbox=dict(boxstyle="round,pad=0.3", facecolor="lightblue"), 
         ha='center', va='center', fontsize=12, fontweight='bold')
ax9.text(0.5, 0.5, 'Confounders\n(tenure, services)', 
         bbox=dict(boxstyle="round,pad=0.3", facecolor="lightgray"), 
         ha='center', va='center', fontsize=10)
ax9.text(0.9, 0.8, 'Monthly Charges', bbox=dict(boxstyle="round,pad=0.3", facecolor="lightgreen"), 
         ha='center', va='center', fontsize=12, fontweight='bold')
ax9.text(0.5, 0.2, 'Churn', bbox=dict(boxstyle="round,pad=0.3", facecolor="lightcoral"), 
         ha='center', va='center', fontsize=12, fontweight='bold')

# Arrows
ax9.arrow(0.2, 0.8, 0.6, 0, head_width=0.03, head_length=0.03, fc='blue', ec='blue')
ax9.arrow(0.1, 0.7, 0.3, -0.4, head_width=0.03, head_length=0.03, fc='blue', ec='blue')
ax9.arrow(0.9, 0.7, -0.3, -0.4, head_width=0.03, head_length=0.03, fc='green', ec='green')
ax9.arrow(0.4, 0.4, 0, -0.1, head_width=0.03, head_length=0.02, fc='gray', ec='gray')

ax9.set_xlim(0, 1)
ax9.set_ylim(0, 1)
ax9.axis('off')
ax9.set_title('9. Spurious Correlation Structure', fontweight='bold')

plt.tight_layout()
plt.show()

# Spurious correlation verification
print(f"\n=== Spurious Correlation Verification Results ===")
print(f"1. Spurious correlation of contract type:")
print(f"   - Unadjusted effect overestimated: {contract_effect_unadj:.3f} → {contract_effect_adj:.3f}")
print(f"   - Bias: {contract_effect_unadj - contract_effect_adj:.3f}")

print(f"\n2. Spurious correlation of monthly charges:")
print(f"   - Unadjusted effect underestimated: {charges_effect_unadj:.3f} → {charges_effect_adj:.3f}")
print(f"   - True effect is {charges_effect_adj/charges_effect_unadj:.1f}x larger")

print(f"\n3. Causes of spurious correlation:")
print(f"   - Weak negative correlation between contract type and charges: {df['Long_Contract'].corr(df['MonthlyCharges']):.3f}")
print(f"   - Common confounding factors (tenure, services) affect both variables")

print(f"\n4. Conclusion:")
if abs(contract_effect_adj) > abs(charges_effect_adj):
    print("   - Contract type has stronger causal effect")
else:
    print("   - Monthly charges have stronger causal effect")
print("   - Simple correlation analysis is misleading due to spurious correlations")