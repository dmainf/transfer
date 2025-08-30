import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Load data
df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
df = df_raw.copy()
df['Churn_Binary'] = (df['Churn'] == 'Yes').astype(int)

# Extract churned customers only
churned_customers = df[df['Churn_Binary'] == 1]

print(f"=== Churned Customer Distribution Visualization (Count-based) ===")
print(f"Total churned customers: {len(churned_customers):,} customers")

# Create charge levels
df['Charge_Level'] = pd.cut(df['MonthlyCharges'],
                           bins=[0, 30, 50, 70, 90, 120],
                           labels=['Very Low\n(<$30)', 'Low\n($30-50)', 'Medium\n($50-70)',
                                  'High\n($70-90)', 'Very High\n(>$90)'])

churned_customers['Charge_Level'] = pd.cut(churned_customers['MonthlyCharges'],
                                          bins=[0, 30, 50, 70, 90, 120],
                                          labels=['Very Low\n(<$30)', 'Low\n($30-50)', 'Medium\n($50-70)',
                                                 'High\n($70-90)', 'Very High\n(>$90)'])

# Visualization
fig, axes = plt.subplots(2, 3, figsize=(18, 12))
fig.suptitle('Churned Customer Distribution (Count)', fontsize=16, fontweight='bold')

# 1. Churned customers by contract type
ax1 = axes[0, 0]
contract_counts = churned_customers['Contract'].value_counts()
bars1 = ax1.bar(contract_counts.index, contract_counts.values, color=['red', 'orange', 'lightcoral'])
ax1.set_title('1. Churned Customers by Contract Type', fontsize=14, fontweight='bold')
ax1.set_ylabel('Number of Churned Customers')
ax1.set_xlabel('Contract Type')

# Display values on bars
for bar in bars1:
    height = bar.get_height()
    ax1.text(bar.get_x() + bar.get_width()/2., height + 10,
             f'{int(height):,}', ha='center', va='bottom', fontweight='bold')

plt.setp(ax1.xaxis.get_majorticklabels(), rotation=45)

# 2. Churned customers by monthly charge level
ax2 = axes[0, 1]
charge_counts = churned_customers['Charge_Level'].value_counts().reindex(['Very Low\n(<$30)', 'Low\n($30-50)', 'Medium\n($50-70)', 
                                                                         'High\n($70-90)', 'Very High\n(>$90)'])
bars2 = ax2.bar(range(len(charge_counts)), charge_counts.values,
                color=['lightblue', 'skyblue', 'gold', 'orange', 'red'])
ax2.set_title('2. Churned Customers by Monthly Charge Level', fontsize=14, fontweight='bold')
ax2.set_ylabel('Number of Churned Customers')
ax2.set_xlabel('Monthly Charge Level')
ax2.set_xticks(range(len(charge_counts)))
ax2.set_xticklabels(charge_counts.index, rotation=45)

# Display values on bars
for i, bar in enumerate(bars2):
    height = bar.get_height()
    ax2.text(bar.get_x() + bar.get_width()/2., height + 5,
             f'{int(height):,}', ha='center', va='bottom', fontweight='bold')

# 3. 2D distribution of contract type and monthly charges (heatmap)
ax3 = axes[0, 2]
pivot_churned = churned_customers.pivot_table(values='Churn_Binary', 
                                            index='Contract', 
                                            columns='Charge_Level', 
                                            aggfunc='count', 
                                            fill_value=0)
sns.heatmap(pivot_churned, annot=True, fmt='d', cmap='Reds', ax=ax3, cbar_kws={'label': 'Number of Churned Customers'})
ax3.set_title('3. Contract Type × Charge Level\nChurned Customers Heatmap', fontsize=14, fontweight='bold')
ax3.set_ylabel('Contract Type')
ax3.set_xlabel('Monthly Charge Level')

# 4. Monthly charge distribution by contract type (histogram)
ax4 = axes[1, 0]
contracts = ['Month-to-month', 'One year', 'Two year']
colors = ['red', 'orange', 'green']
for i, contract in enumerate(contracts):
    subset = churned_customers[churned_customers['Contract'] == contract]
    ax4.hist(subset['MonthlyCharges'], bins=20, alpha=0.7, 
             label=f'{contract} (n={len(subset)})', color=colors[i])

ax4.set_title('4. Monthly Charge Distribution by Contract\n(Churned Customers Only)', fontsize=14, fontweight='bold')
ax4.set_xlabel('Monthly Charges ($)')
ax4.set_ylabel('Number of Churned Customers')
ax4.legend()
ax4.grid(True, alpha=0.3)

# 5. Monthly charges scatter plot (color-coded by contract type)
ax5 = axes[1, 1]
for i, contract in enumerate(contracts):
    subset = churned_customers[churned_customers['Contract'] == contract]
    ax5.scatter(subset['MonthlyCharges'], np.random.normal(i, 0.1, len(subset)),
               alpha=0.6, label=f'{contract} (n={len(subset)})', 
               color=colors[i], s=30)

ax5.set_title('5. Monthly Charges Distribution\n(Churned Customers by Contract)', fontsize=14, fontweight='bold')
ax5.set_xlabel('Monthly Charges ($)')
ax5.set_yticks(range(len(contracts)))
ax5.set_yticklabels(contracts)
ax5.legend()
ax5.grid(True, alpha=0.3)

# 6. Bar chart of churned customers (contract type × charge level)
ax6 = axes[1, 2]
# Prepare data
detailed_counts = churned_customers.groupby(['Contract', 'Charge_Level']).size().reset_index(name='Count')

# Set X-axis positions
charge_levels = ['Very Low\n(<$30)', 'Low\n($30-50)', 'Medium\n($50-70)', 'High\n($70-90)', 'Very High\n(>$90)']
x = np.arange(len(charge_levels))
width = 0.25

# Draw bars for each contract type
for i, contract in enumerate(contracts):
    contract_data = detailed_counts[detailed_counts['Contract'] == contract]
    counts = []
    for level in charge_levels:
        count = contract_data[contract_data['Charge_Level'] == level]['Count']
        counts.append(count.iloc[0] if len(count) > 0 else 0)
    
    ax6.bar(x + i * width, counts, width, label=contract, color=colors[i], alpha=0.8)

ax6.set_title('6. Contract Type × Charge Level\nChurned Customer Count', fontsize=14, fontweight='bold')
ax6.set_xlabel('Monthly Charge Level')
ax6.set_ylabel('Number of Churned Customers')
ax6.set_xticks(x + width)
ax6.set_xticklabels(charge_levels, rotation=45)
ax6.legend()
ax6.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# Statistical summary
print("\n=== Statistical Summary ===")
print("\n1. Churned customers by contract type:")
for contract, count in contract_counts.items():
    percentage = count / len(churned_customers) * 100
    print(f"  {contract}: {count:,} customers ({percentage:.1f}%)")

print("\n2. Churned customers by monthly charge level:")
for level, count in charge_counts.items():
    percentage = count / len(churned_customers) * 100
    print(f"  {level.replace(chr(10), ' ')}: {count:,} customers ({percentage:.1f}%)")

print("\n3. Segments with most churned customers (top 5):")
segment_counts = churned_customers.groupby(['Contract', 'Charge_Level']).size().sort_values(ascending=False)
for i, ((contract, level), count) in enumerate(segment_counts.head().items()):
    percentage = count / len(churned_customers) * 100
    print(f"  {i+1}. {contract} × {level.replace(chr(10), ' ')}: {count:,} customers ({percentage:.1f}%)")

print(f"\n4. Monthly charge statistics for churned customers:")
print(f"  Mean: ${churned_customers['MonthlyCharges'].mean():.2f}")
print(f"  Median: ${churned_customers['MonthlyCharges'].median():.2f}")
print(f"  Standard deviation: ${churned_customers['MonthlyCharges'].std():.2f}")
print(f"  Minimum: ${churned_customers['MonthlyCharges'].min():.2f}")
print(f"  Maximum: ${churned_customers['MonthlyCharges'].max():.2f}")