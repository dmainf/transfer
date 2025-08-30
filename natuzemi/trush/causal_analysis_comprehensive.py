import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LogisticRegression, LinearRegression
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
import warnings
warnings.filterwarnings('ignore')

class ComprehensiveCausalAnalysis:
    def __init__(self, df):
        self.df = df.copy()
        self.prepare_data()
        
    def prepare_data(self):
        """データ準備"""
        # Binary variables
        self.df['Churn_Binary'] = (self.df['Churn'] == 'Yes').astype(int)
        self.df['Long_Contract'] = (self.df['Contract'] != 'Month-to-month').astype(int)
        
        # Standardize continuous variables
        scaler = StandardScaler()
        self.df['MonthlyCharges_Std'] = scaler.fit_transform(self.df[['MonthlyCharges']])
        
        # Convert categorical to binary
        for col in ['Partner', 'Dependents', 'PhoneService', 'PaperlessBilling']:
            self.df[col + '_Binary'] = (self.df[col] == 'Yes').astype(int)
            
        # Handle TotalCharges
        self.df['TotalCharges_Numeric'] = pd.to_numeric(self.df['TotalCharges'], errors='coerce')
        self.df['TotalCharges_Numeric'] = self.df['TotalCharges_Numeric'].fillna(self.df['TotalCharges_Numeric'].median())
        
        print("データ準備完了")
        
    def estimate_individual_effects(self):
        """個別の因果効果を推定"""
        print("=== 個別因果効果の推定 ===\n")
        
        # Confounders (共通の交絡因子)
        confounders = ['SeniorCitizen', 'Partner_Binary', 'Dependents_Binary', 
                      'tenure', 'PhoneService_Binary', 'TotalCharges_Numeric']
        
        results = {}
        
        # 1. Contract Type Effect (controlling for charges and confounders)
        print("1. 契約タイプの因果効果 (月額料金と交絡因子をコントロール)")
        X_contract = self.df[['Long_Contract', 'MonthlyCharges_Std'] + confounders]
        y = self.df['Churn_Binary']
        
        model_contract = LogisticRegression(random_state=42)
        model_contract.fit(X_contract, y)
        
        contract_effect = model_contract.coef_[0][0]  # Long_Contract coefficient
        charges_effect_controlled = model_contract.coef_[0][1]  # MonthlyCharges coefficient
        
        print(f"契約タイプ効果 (調整済み): {contract_effect:.3f}")
        print(f"月額料金効果 (調整済み): {charges_effect_controlled:.3f}")
        
        # Odds ratios
        contract_or = np.exp(contract_effect)
        charges_or = np.exp(charges_effect_controlled)
        
        print(f"契約タイプオッズ比: {contract_or:.3f} (長期契約で解約オッズが{(1-contract_or)*100:.1f}%減少)")
        print(f"月額料金オッズ比: {charges_or:.3f} (1SD増加で解約オッズが{(charges_or-1)*100:.1f}%増加)")
        
        results['contract_effect'] = contract_effect
        results['charges_effect_controlled'] = charges_effect_controlled
        
        # 2. Monthly Charges Effect (controlling for contract and confounders)
        print(f"\n2. 月額料金の因果効果 (契約タイプと交絡因子をコントロール)")
        print(f"上記と同じ: {charges_effect_controlled:.3f}")
        
        # 3. Unadjusted effects for comparison
        print(f"\n3. 未調整効果との比較")
        
        # Contract only
        X_contract_only = self.df[['Long_Contract']]
        model_contract_only = LogisticRegression(random_state=42)
        model_contract_only.fit(X_contract_only, y)
        contract_effect_unadj = model_contract_only.coef_[0][0]
        
        # Charges only
        X_charges_only = self.df[['MonthlyCharges_Std']]
        model_charges_only = LogisticRegression(random_state=42)
        model_charges_only.fit(X_charges_only, y)
        charges_effect_unadj = model_charges_only.coef_[0][0]
        
        print(f"契約タイプ効果 (未調整): {contract_effect_unadj:.3f}")
        print(f"月額料金効果 (未調整): {charges_effect_unadj:.3f}")
        print(f"契約タイプ バイアス: {contract_effect_unadj - contract_effect:.3f}")
        print(f"月額料金 バイアス: {charges_effect_unadj - charges_effect_controlled:.3f}")
        
        results['contract_effect_unadj'] = contract_effect_unadj
        results['charges_effect_unadj'] = charges_effect_unadj
        
        return results
    
    def interaction_analysis(self):
        """相互作用効果の分析"""
        print(f"\n=== 相互作用効果の分析 ===\n")
        
        # Create interaction term
        self.df['Contract_Charges_Interaction'] = self.df['Long_Contract'] * self.df['MonthlyCharges_Std']
        
        confounders = ['SeniorCitizen', 'Partner_Binary', 'Dependents_Binary', 
                      'tenure', 'PhoneService_Binary', 'TotalCharges_Numeric']
        
        X_interaction = self.df[['Long_Contract', 'MonthlyCharges_Std', 'Contract_Charges_Interaction'] + confounders]
        y = self.df['Churn_Binary']
        
        model_interaction = LogisticRegression(random_state=42)
        model_interaction.fit(X_interaction, y)
        
        contract_main = model_interaction.coef_[0][0]
        charges_main = model_interaction.coef_[0][1]
        interaction_effect = model_interaction.coef_[0][2]
        
        print(f"契約タイプ主効果: {contract_main:.3f}")
        print(f"月額料金主効果: {charges_main:.3f}")
        print(f"相互作用効果: {interaction_effect:.3f}")
        
        # Interpretation
        if abs(interaction_effect) > 0.1:
            print(f"\n相互作用効果が存在: {interaction_effect:.3f}")
            if interaction_effect > 0:
                print("長期契約は高料金顧客の解約リスクを増加させる")
            else:
                print("長期契約は高料金顧客の解約リスクを特に減少させる")
        else:
            print("\n相互作用効果は小さい: 契約タイプと月額料金は独立して作用")
            
        return {
            'contract_main': contract_main,
            'charges_main': charges_main,
            'interaction_effect': interaction_effect
        }
    
    def dose_response_by_contract(self):
        """契約タイプ別の用量反応関係"""
        print(f"\n=== 契約タイプ別の用量反応関係 ===\n")
        
        # Create charge quintiles
        self.df['Charge_Quintile'] = pd.qcut(self.df['MonthlyCharges'], 
                                           q=5, labels=['Q1', 'Q2', 'Q3', 'Q4', 'Q5'])
        
        # Analyze by contract type
        dose_response = self.df.groupby(['Contract', 'Charge_Quintile']).agg({
            'Churn_Binary': ['mean', 'count'],
            'MonthlyCharges': 'mean'
        }).round(3)
        
        print("契約タイプ別の用量反応関係:")
        print(dose_response)
        
        # Visualization
        plt.figure(figsize=(12, 8))
        
        contracts = self.df['Contract'].unique()
        colors = ['red', 'orange', 'green']
        
        plt.subplot(2, 2, 1)
        for i, contract in enumerate(contracts):
            subset = self.df[self.df['Contract'] == contract]
            charge_response = subset.groupby('Charge_Quintile')['Churn_Binary'].mean()
            charge_means = subset.groupby('Charge_Quintile')['MonthlyCharges'].mean()
            
            plt.plot(charge_means.values, charge_response.values, 
                    'o-', label=contract, color=colors[i], linewidth=2, markersize=6)
        
        plt.xlabel('Average Monthly Charges ($)')
        plt.ylabel('Churn Rate')
        plt.title('Dose-Response by Contract Type')
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        # Heatmap
        plt.subplot(2, 2, 2)
        pivot_churn = self.df.pivot_table(values='Churn_Binary', 
                                        index='Contract', 
                                        columns='Charge_Quintile', 
                                        aggfunc='mean')
        sns.heatmap(pivot_churn, annot=True, fmt='.3f', cmap='YlOrRd')
        plt.title('Churn Rate Heatmap')
        
        # Count heatmap
        plt.subplot(2, 2, 3)
        pivot_count = self.df.pivot_table(values='Churn_Binary', 
                                        index='Contract', 
                                        columns='Charge_Quintile', 
                                        aggfunc='count')
        sns.heatmap(pivot_count, annot=True, fmt='d', cmap='Blues')
        plt.title('Customer Count')
        
        # Churned count heatmap
        plt.subplot(2, 2, 4)
        pivot_churned = self.df.pivot_table(values='Churn_Binary', 
                                          index='Contract', 
                                          columns='Charge_Quintile', 
                                          aggfunc='sum')
        sns.heatmap(pivot_churned, annot=True, fmt='d', cmap='Reds')
        plt.title('Churned Customer Count')
        
        plt.tight_layout()
        plt.show()
        
        return dose_response
    
    def propensity_score_analysis_detailed(self):
        """詳細な傾向スコア分析"""
        print(f"\n=== 詳細な傾向スコア分析 ===\n")
        
        # 1. Contract type propensity
        confounders = ['SeniorCitizen', 'Partner_Binary', 'Dependents_Binary', 
                      'tenure', 'PhoneService_Binary', 'MonthlyCharges_Std', 'TotalCharges_Numeric']
        
        X_conf = self.df[confounders]
        treatment_contract = self.df['Long_Contract']
        outcome = self.df['Churn_Binary']
        
        # Estimate propensity scores for contract
        ps_model_contract = LogisticRegression(random_state=42)
        ps_model_contract.fit(X_conf, treatment_contract)
        ps_contract = ps_model_contract.predict_proba(X_conf)[:, 1]
        
        # IPW estimation for contract
        treated_contract = self.df[self.df['Long_Contract'] == 1]
        control_contract = self.df[self.df['Long_Contract'] == 0]
        
        ps_treated = ps_contract[self.df['Long_Contract'] == 1]
        ps_control = ps_contract[self.df['Long_Contract'] == 0]
        
        outcome_treated = outcome[self.df['Long_Contract'] == 1]
        outcome_control = outcome[self.df['Long_Contract'] == 0]
        
        # Avoid extreme weights
        ps_treated = np.clip(ps_treated, 0.01, 0.99)
        ps_control = np.clip(ps_control, 0.01, 0.99)
        
        ate_treated = np.mean(outcome_treated / ps_treated)
        ate_control = np.mean(outcome_control / (1 - ps_control))
        ate_contract = ate_treated - ate_control
        
        simple_diff_contract = outcome_treated.mean() - outcome_control.mean()
        
        print(f"契約タイプの因果効果:")
        print(f"単純差分 (バイアス含む): {simple_diff_contract:.3f}")
        print(f"IPW推定値 (因果効果): {ate_contract:.3f}")
        print(f"バイアス補正: {simple_diff_contract - ate_contract:.3f}")
        
        return {
            'ate_contract': ate_contract,
            'simple_diff_contract': simple_diff_contract,
            'bias_contract': simple_diff_contract - ate_contract
        }
    
    def comprehensive_summary(self, individual_results, interaction_results, ps_results):
        """総合的な結果サマリー"""
        print(f"\n" + "="*60)
        print("総合的因果推論結果")
        print("="*60)
        
        print(f"\n1. 主要因果効果 (ロジスティック回帰係数)")
        print(f"契約タイプ効果 (調整済み): {individual_results['contract_effect']:.3f}")
        print(f"月額料金効果 (調整済み): {individual_results['charges_effect_controlled']:.3f}")
        
        print(f"\n2. オッズ比での解釈")
        contract_or = np.exp(individual_results['contract_effect'])
        charges_or = np.exp(individual_results['charges_effect_controlled'])
        print(f"長期契約 → 解約オッズが {(1-contract_or)*100:.1f}% 減少")
        print(f"料金1SD増加 → 解約オッズが {(charges_or-1)*100:.1f}% 増加")
        
        print(f"\n3. 傾向スコア分析 (確率差)")
        print(f"契約タイプの因果効果: {ps_results['ate_contract']:.3f} ({ps_results['ate_contract']*100:.1f}ポイント)")
        
        print(f"\n4. 相互作用効果")
        if abs(interaction_results['interaction_effect']) > 0.1:
            print(f"有意な相互作用あり: {interaction_results['interaction_effect']:.3f}")
        else:
            print(f"相互作用なし: {interaction_results['interaction_effect']:.3f}")
            
        print(f"\n5. バイアスの大きさ")
        print(f"契約タイプのバイアス: {ps_results['bias_contract']:.3f}")
        
        print(f"\n6. 結論")
        contract_effect_size = abs(individual_results['contract_effect'])
        charges_effect_size = abs(individual_results['charges_effect_controlled'])
        
        if contract_effect_size > charges_effect_size * 2:
            main_cause = "契約タイプ"
            secondary_cause = "月額料金"
        elif charges_effect_size > contract_effect_size * 2:
            main_cause = "月額料金"
            secondary_cause = "契約タイプ"
        else:
            main_cause = "契約タイプと月額料金の両方"
            secondary_cause = None
            
        print(f"主要な解約原因: {main_cause}")
        if secondary_cause:
            print(f"副次的要因: {secondary_cause}")
            
        print(f"\n実用的含意:")
        print(f"- 契約タイプ変更の効果: 解約率を{abs(ps_results['ate_contract'])*100:.1f}ポイント削減")
        print(f"- 料金政策の効果: 料金1SD削減で解約率を{abs(individual_results['charges_effect_controlled'])*charges_or*100:.1f}ポイント削減")

def main():
    # Load data
    df_raw = pd.read_csv('WA_Fn-UseC_-Telco-Customer-Churn.csv')
    
    # Initialize analysis
    analyzer = ComprehensiveCausalAnalysis(df_raw)
    
    print("=== 契約タイプと月額料金の解約に対する因果効果分析 ===\n")
    
    # Run analyses
    individual_results = analyzer.estimate_individual_effects()
    interaction_results = analyzer.interaction_analysis()
    dose_response = analyzer.dose_response_by_contract()
    ps_results = analyzer.propensity_score_analysis_detailed()
    
    # Comprehensive summary
    analyzer.comprehensive_summary(individual_results, interaction_results, ps_results)

if __name__ == "__main__":
    main()