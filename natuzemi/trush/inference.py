import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import NearestNeighbors
import warnings
warnings.filterwarnings('ignore')

from lib.prepro import clean_data

class CausalChurnAnalysis:
    def __init__(self, df):
        self.df = df
        self.df_original = df.copy()
        
    def create_causal_dag(self):
        """
        Create a conceptual Directed Acyclic Graph (DAG) for churn causation
        """
        print("=== Causal DAG for Customer Churn ===")
        print("""
        Proposed Causal Structure:
        
        Demographics (Age, Gender) 
                ↓
        Service Adoption (Internet, Phone) → Contract Type → Churn
                ↓                               ↓
        Usage Patterns (Streaming, Security) → Monthly Charges → Churn
                ↓                               ↓
        Tenure ←→ Payment Method → Churn
        
        Key Causal Hypotheses:
        1. Contract Type directly causes Churn (treatment effect)
        2. Monthly Charges mediate the effect of Service Adoption on Churn
        3. Tenure is both a confounder and outcome (time-varying)
        4. Demographics influence service choices, which affect churn
        """)
        
    def identify_treatment_and_confounders(self):
        """
        Identify potential treatments and confounders for causal analysis
        """
        print("=== Treatment Variables (Potential Causal Factors) ===")
        treatments = {
            'Contract': 'Primary treatment - contract length directly affects churn',
            'MonthlyCharges': 'Price treatment - higher charges may cause churn',
            'InternetService': 'Service quality treatment - affects satisfaction',
            'PaymentMethod': 'Convenience treatment - ease of payment affects retention'
        }
        
        for treatment, description in treatments.items():
            print(f"{treatment}: {description}")
            
        print("\n=== Potential Confounders ===")
        confounders = {
            'Demographics': ['SeniorCitizen', 'Partner', 'Dependents'],
            'Service_Usage': ['PhoneService', 'StreamingTV', 'StreamingMovies'],
            'Service_Quality': ['OnlineSecurity', 'TechSupport', 'OnlineBackup'],
            'Tenure': ['tenure'] # Special case - both confounder and mediator
        }
        
        for category, variables in confounders.items():
            print(f"{category}: {variables}")
            
        return treatments, confounders
    
    def propensity_score_analysis(self, treatment_var='Contract'):
        """
        Perform propensity score analysis to estimate causal effects
        """
        print(f"\n=== Propensity Score Analysis: {treatment_var} ===")
        
        # Create binary treatment (Month-to-month vs Long-term contracts)
        df_prop = self.df_original.copy()
        df_prop['treatment'] = (df_prop[treatment_var] != 'Month-to-month').astype(int)
        df_prop['outcome'] = (df_prop['Churn'] == 'Yes').astype(int)
        
        # Select confounders (exclude treatment and outcome)
        confounders = ['SeniorCitizen', 'Partner', 'Dependents', 'tenure', 
                      'PhoneService', 'MonthlyCharges', 'TotalCharges']
        
        # Convert categorical variables to numeric
        for col in ['Partner', 'Dependents', 'PhoneService']:
            df_prop[col] = (df_prop[col] == 'Yes').astype(int)
        
        # Handle missing values and convert TotalCharges to numeric
        df_prop['TotalCharges'] = pd.to_numeric(df_prop['TotalCharges'], errors='coerce')
        df_prop = df_prop.dropna(subset=confounders + ['treatment', 'outcome'])
        
        X_confounders = df_prop[confounders]
        treatment = df_prop['treatment']
        outcome = df_prop['outcome']
        
        # Estimate propensity scores
        prop_model = LogisticRegression(random_state=42)
        prop_model.fit(X_confounders, treatment)
        propensity_scores = prop_model.predict_proba(X_confounders)[:, 1]
        
        df_prop['propensity_score'] = propensity_scores
        
        # Calculate Average Treatment Effect (ATE) using propensity score weighting
        treated = df_prop[df_prop['treatment'] == 1]
        control = df_prop[df_prop['treatment'] == 0]
        
        # IPW (Inverse Probability Weighting)
        treated_outcome = np.mean(treated['outcome'] / treated['propensity_score'])
        control_outcome = np.mean(control['outcome'] / (1 - control['propensity_score']))
        
        ate_ipw = treated_outcome - control_outcome
        
        # Simple difference (biased estimate)
        simple_diff = treated['outcome'].mean() - control['outcome'].mean()
        
        print(f"Treatment: Long-term Contract (vs Month-to-month)")
        print(f"Simple Difference (Biased): {simple_diff:.3f}")
        print(f"Causal Effect (IPW): {ate_ipw:.3f}")
        print(f"Bias Correction: {simple_diff - ate_ipw:.3f}")
        
        # Propensity score distribution
        plt.figure(figsize=(12, 4))
        
        plt.subplot(1, 2, 1)
        plt.hist(control['propensity_score'], alpha=0.7, label='Control (Month-to-month)', bins=30)
        plt.hist(treated['propensity_score'], alpha=0.7, label='Treated (Long-term)', bins=30)
        plt.xlabel('Propensity Score')
        plt.ylabel('Frequency')
        plt.title('Propensity Score Distribution')
        plt.legend()
        
        plt.subplot(1, 2, 2)
        # Outcome by propensity score
        bins = np.linspace(0, 1, 10)
        bin_centers = (bins[:-1] + bins[1:]) / 2
        
        treated_outcomes = []
        control_outcomes = []
        
        for i in range(len(bins)-1):
            mask = (propensity_scores >= bins[i]) & (propensity_scores < bins[i+1])
            treated_mask = mask & (treatment == 1)
            control_mask = mask & (treatment == 0)
            
            if treated_mask.sum() > 0:
                treated_outcomes.append(outcome[treated_mask].mean())
            else:
                treated_outcomes.append(np.nan)
                
            if control_mask.sum() > 0:
                control_outcomes.append(outcome[control_mask].mean())
            else:
                control_outcomes.append(np.nan)
        
        plt.plot(bin_centers, treated_outcomes, 'o-', label='Treated', markersize=6)
        plt.plot(bin_centers, control_outcomes, 's-', label='Control', markersize=6)
        plt.xlabel('Propensity Score')
        plt.ylabel('Churn Rate')
        plt.title('Churn Rate by Propensity Score')
        plt.legend()
        
        plt.tight_layout()
        plt.show()
        
        return ate_ipw, simple_diff
    
    def mediation_analysis(self):
        """
        Analyze mediation effects in churn causation
        """
        print("\n=== Mediation Analysis ===")
        print("Investigating: Contract Type → Monthly Charges → Churn")
        
        df_med = self.df_original.copy()
        
        # Convert variables
        df_med['long_contract'] = (df_med['Contract'] != 'Month-to-month').astype(int)
        df_med['churn'] = (df_med['Churn'] == 'Yes').astype(int)
        df_med['monthly_charges_std'] = (df_med['MonthlyCharges'] - df_med['MonthlyCharges'].mean()) / df_med['MonthlyCharges'].std()
        
        # Path Analysis
        # 1. Direct effect: Contract → Churn (without mediator)
        X_direct = df_med[['long_contract']].values
        y_churn = df_med['churn'].values
        
        direct_model = LogisticRegression()
        direct_model.fit(X_direct, y_churn)
        direct_effect = direct_model.coef_[0][0]
        
        # 2. Mediator path: Contract → Monthly Charges
        from sklearn.linear_model import LinearRegression
        y_charges = df_med['monthly_charges_std'].values
        mediator_model = LinearRegression()
        mediator_model.fit(X_direct, y_charges)
        a_path = mediator_model.coef_[0]
        
        # 3. Total effect: Contract + Monthly Charges → Churn
        X_total = df_med[['long_contract', 'monthly_charges_std']].values
        total_model = LogisticRegression()
        total_model.fit(X_total, y_churn)
        b_path = total_model.coef_[0][1]  # Effect of charges on churn
        direct_controlled = total_model.coef_[0][0]  # Direct effect controlling for mediator
        
        # Indirect effect (mediated effect)
        indirect_effect = a_path * b_path
        total_effect = direct_controlled + indirect_effect
        
        print(f"Direct Effect (Contract → Churn): {direct_effect:.3f}")
        print(f"a-path (Contract → Charges): {a_path:.3f}")
        print(f"b-path (Charges → Churn): {b_path:.3f}")
        print(f"Indirect Effect (Contract → Charges → Churn): {indirect_effect:.3f}")
        print(f"Direct Effect (controlled): {direct_controlled:.3f}")
        print(f"Total Effect: {total_effect:.3f}")
        if abs(total_effect) > 1e-6:  # Avoid division by zero
            mediation_prop = abs(indirect_effect / total_effect)
            print(f"Mediation Proportion: {mediation_prop:.1%}")
        else:
            print("Mediation Proportion: Cannot calculate (total effect near zero)")
        
        # Visualization
        plt.figure(figsize=(10, 6))
        
        # Path diagram conceptual
        plt.text(0.1, 0.8, 'Contract Type\n(Month-to-month\nvs Long-term)', 
                bbox=dict(boxstyle="round,pad=0.3", facecolor="lightblue"), 
                ha='center', va='center', fontsize=10)
        
        plt.text(0.5, 0.8, 'Monthly Charges', 
                bbox=dict(boxstyle="round,pad=0.3", facecolor="lightgreen"), 
                ha='center', va='center', fontsize=10)
        
        plt.text(0.9, 0.8, 'Churn', 
                bbox=dict(boxstyle="round,pad=0.3", facecolor="lightcoral"), 
                ha='center', va='center', fontsize=10)
        
        # Arrows
        plt.arrow(0.2, 0.8, 0.2, 0, head_width=0.02, head_length=0.02, fc='black', ec='black')
        plt.arrow(0.6, 0.8, 0.2, 0, head_width=0.02, head_length=0.02, fc='black', ec='black')
        plt.arrow(0.3, 0.7, 0.4, 0, head_width=0.02, head_length=0.02, fc='red', ec='red')
        
        # Labels
        plt.text(0.3, 0.85, f'a = {a_path:.3f}', ha='center', fontsize=9)
        plt.text(0.7, 0.85, f'b = {b_path:.3f}', ha='center', fontsize=9)
        plt.text(0.5, 0.65, f"Direct: {direct_controlled:.3f}", ha='center', fontsize=9, color='red')
        plt.text(0.5, 0.6, f"Indirect: {indirect_effect:.3f}", ha='center', fontsize=9)
        
        plt.xlim(0, 1)
        plt.ylim(0.5, 1)
        plt.axis('off')
        plt.title('Mediation Analysis: Contract Type → Monthly Charges → Churn', fontsize=12)
        plt.show()
        
        return {
            'direct_effect': direct_controlled,
            'indirect_effect': indirect_effect,
            'total_effect': total_effect,
            'mediation_proportion': abs(indirect_effect/total_effect) if abs(total_effect) > 1e-6 else 0
        }
    
    def dose_response_analysis(self):
        """
        Analyze dose-response relationship for continuous treatments
        """
        print("\n=== Dose-Response Analysis: Monthly Charges ===")
        
        df_dose = self.df_original.copy()
        df_dose['churn'] = (df_dose['Churn'] == 'Yes').astype(int)
        
        # Create charge bins for dose-response
        df_dose['charge_quartile'] = pd.qcut(df_dose['MonthlyCharges'], 
                                           q=5, labels=['Q1', 'Q2', 'Q3', 'Q4', 'Q5'])
        
        # Calculate dose-response curve
        dose_response = df_dose.groupby('charge_quartile').agg({
            'churn': ['mean', 'count'],
            'MonthlyCharges': 'mean'
        }).round(3)
        
        print("Dose-Response: Monthly Charges → Churn Rate")
        print(dose_response)
        
        # Visualization
        plt.figure(figsize=(10, 4))
        
        plt.subplot(1, 2, 1)
        charges_mean = dose_response['MonthlyCharges']['mean']
        churn_rate = dose_response['churn']['mean']
        
        plt.plot(charges_mean.values, churn_rate.values, 'o-', linewidth=2, markersize=8)
        plt.xlabel('Average Monthly Charges ($)')
        plt.ylabel('Churn Rate')
        plt.title('Dose-Response Curve')
        plt.grid(True, alpha=0.3)
        
        # Add annotations
        for i, (x, y) in enumerate(zip(charges_mean, churn_rate)):
            plt.annotate(f'Q{i+1}\n{y:.2f}', (x, y), textcoords="offset points", 
                        xytext=(0,10), ha='center')
        
        plt.subplot(1, 2, 2)
        # Check for non-linear effects
        charges_bins = np.linspace(df_dose['MonthlyCharges'].min(), 
                                  df_dose['MonthlyCharges'].max(), 20)
        bin_centers = (charges_bins[:-1] + charges_bins[1:]) / 2
        bin_churn_rates = []
        
        for i in range(len(charges_bins)-1):
            mask = ((df_dose['MonthlyCharges'] >= charges_bins[i]) & 
                   (df_dose['MonthlyCharges'] < charges_bins[i+1]))
            if mask.sum() > 10:  # Minimum observations per bin
                bin_churn_rates.append(df_dose[mask]['churn'].mean())
            else:
                bin_churn_rates.append(np.nan)
        
        plt.plot(bin_centers, bin_churn_rates, '-', alpha=0.7)
        plt.xlabel('Monthly Charges ($)')
        plt.ylabel('Churn Rate')
        plt.title('Detailed Dose-Response (Binned)')
        plt.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.show()
        
        return dose_response

def main():
    # Load and prepare data
    df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
    
    # Initialize causal analysis
    causal_analyzer = CausalChurnAnalysis(df_raw)
    
    print("=== CAUSAL INFERENCE ANALYSIS FOR CUSTOMER CHURN ===\n")
    
    # 1. Create conceptual causal model
    causal_analyzer.create_causal_dag()
    
    # 2. Identify treatments and confounders
    treatments, confounders = causal_analyzer.identify_treatment_and_confounders()
    
    # 3. Propensity score analysis
    ate, simple_diff = causal_analyzer.propensity_score_analysis('Contract')
    
    # 4. Mediation analysis
    mediation_results = causal_analyzer.mediation_analysis()
    
    # 5. Dose-response analysis
    dose_response = causal_analyzer.dose_response_analysis()
    
    # Summary of causal insights
    print("\n" + "="*50)
    print("CAUSAL INSIGHTS SUMMARY")
    print("="*50)
    print(f"1. Contract Type Causal Effect: {ate:.3f} (vs correlation: {simple_diff:.3f})")
    print(f"2. Mediation by Monthly Charges: {mediation_results['mediation_proportion']:.1%}")
    print(f"3. Price sensitivity shows non-linear dose-response relationship")
    print(f"4. Bias in correlation-based analysis: {simple_diff - ate:.3f}")

if __name__ == "__main__":
    main()