import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from lib.prepro import clean_data

# Data loading and preprocessing
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df_original = df_raw.copy()
df_original['Churn'] = df_original['Churn'].apply(lambda x: 1 if x == 'Yes' else 0)

print("=== Relationship Analysis: Tenure vs Monthly Charges ===")

# Calculate correlation coefficient
correlation = df_original['tenure'].corr(df_original['MonthlyCharges'])
print(f"Correlation coefficient between Tenure and Monthly Charges: {correlation:.4f}")

# Basic statistics
print(f"\nTenure statistics:")
print(df_original['tenure'].describe())
print(f"\nMonthly Charges statistics:")
print(df_original['MonthlyCharges'].describe())

# Create tenure groups for analysis
df_original['tenure_group'] = pd.cut(df_original['tenure'], 
                                   bins=[0, 12, 24, 36, 48, 100], 
                                   labels=['0-12M', '13-24M', '25-36M', '37-48M', '49M+'])

# Analyze monthly charges by tenure group
print(f"\n=== Monthly Charges by Tenure Group ===")
charges_by_tenure = df_original.groupby('tenure_group')['MonthlyCharges'].agg(['mean', 'median', 'std', 'count'])
charges_by_tenure.columns = ['Mean', 'Median', 'StdDev', 'Count']
print(charges_by_tenure)

# Create visualizations
plt.figure(figsize=(20, 5))

# 1. Scatter plot: Tenure vs Monthly Charges
plt.subplot(1, 4, 1)
plt.scatter(df_original['tenure'], df_original['MonthlyCharges'], alpha=0.5)
plt.xlabel('Tenure (months)')
plt.ylabel('Monthly Charges ($)')
plt.title(f'Tenure vs Monthly Charges\n(Correlation: {correlation:.4f})')

# Add trend line
z = np.polyfit(df_original['tenure'], df_original['MonthlyCharges'], 1)
p = np.poly1d(z)
plt.plot(df_original['tenure'].values, p(df_original['tenure'].values), "r--", alpha=0.8)

# 2. Box plot: Monthly Charges by Tenure Group
plt.subplot(1, 4, 2)
df_original.boxplot(column='MonthlyCharges', by='tenure_group', ax=plt.gca())
plt.title('Monthly Charges Distribution by Tenure Group')
plt.xlabel('Tenure Group')
plt.ylabel('Monthly Charges ($)')
plt.xticks(rotation=45)

# 3. Bar plot: Average Monthly Charges by Tenure Group
plt.subplot(1, 4, 3)
avg_charges = df_original.groupby('tenure_group')['MonthlyCharges'].mean()
bars = plt.bar(range(len(avg_charges)), avg_charges.values)
plt.xlabel('Tenure Group')
plt.ylabel('Average Monthly Charges ($)')
plt.title('Average Monthly Charges by Tenure Group')
plt.xticks(range(len(avg_charges)), avg_charges.index, rotation=45)

# Add value labels on bars
for i, bar in enumerate(bars):
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2., height + 1,
             f'${height:.1f}', ha='center', va='bottom')

# 4. Heatmap: Tenure vs Monthly Charges vs Churn
plt.subplot(1, 4, 4)
# Create charge groups
df_original['charges_group'] = pd.cut(df_original['MonthlyCharges'], 
                                    bins=[0, 35, 55, 75, 120], 
                                    labels=['Low', 'Mid-Low', 'Mid-High', 'High'])

# Create pivot table for heatmap
pivot_table = df_original.groupby(['tenure_group', 'charges_group'])['Churn'].mean().unstack()
sns.heatmap(pivot_table, annot=True, fmt='.2f', cmap='YlOrRd', 
            cbar_kws={'label': 'Churn Rate'})
plt.title('Churn Rate by Tenure & Charges')
plt.xlabel('Monthly Charges Group')
plt.ylabel('Tenure Group')

plt.tight_layout()
plt.show()

# Detailed analysis by segments
print(f"\n=== Detailed Segment Analysis ===")
print("Churn rate by Tenure and Charges segments:")
segment_analysis = df_original.groupby(['tenure_group', 'charges_group']).agg({
    'Churn': ['mean', 'count', 'sum']
}).round(3)
segment_analysis.columns = ['Churn_Rate', 'Customer_Count', 'Churned_Count']
print(segment_analysis)

# Identify high-risk segments
print(f"\n=== High-Risk Segments (Churn Rate > 40%) ===")
high_risk = segment_analysis[segment_analysis['Churn_Rate'] > 0.4]
if not high_risk.empty:
    print(high_risk)
else:
    print("No segments with churn rate > 40%")

# Statistical insights
print(f"\n=== Key Insights ===")
print(f"1. Overall correlation between tenure and monthly charges: {correlation:.4f}")
if abs(correlation) < 0.1:
    print("   -> Very weak correlation")
elif abs(correlation) < 0.3:
    print("   -> Weak correlation")
elif abs(correlation) < 0.7:
    print("   -> Moderate correlation")
else:
    print("   -> Strong correlation")

print(f"2. Highest average monthly charges: {avg_charges.max():.2f} ({avg_charges.idxmax()})")
print(f"3. Lowest average monthly charges: {avg_charges.min():.2f} ({avg_charges.idxmin()})")
print(f"4. Difference in charges between longest and shortest tenure: ${avg_charges.max() - avg_charges.min():.2f}")