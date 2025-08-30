import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.utils import shuffle
from imblearn.over_sampling import SMOTE
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn import metrics
import seaborn as sns

path = "~"
df_raw = pd.read_csv(path + '/WA_Fn-UseC_-Telco-Customer-Churn.csv')

def clean_data(df):
    df.rename(columns={'gender':'Gender'
                       ,'customerID':'CustomerID'
                       ,'Contract':'ContractType'
                       ,'InternetService':'InternetServiceType'
                       ,'tenure':'Tenure'
                      }
              ,inplace=True)


    df['Partner'] = df.Partner.map({'Yes':1,'No':0})
    df['Dependents'] = df.Dependents.map({'Yes':1,'No':0})

    df['PhoneService'] = df.PhoneService.map({'Yes':1,'No':0})
    df['MultipleLines'] = df.MultipleLines.map({'Yes':1,'No':0,'No phone service':0})

    df['InternetService'] = df.InternetServiceType.map({'DSL':1,'Fiber optic':1,'No':0})
    df['OnlineSecurity'] = df.OnlineSecurity.map({'Yes':1,'No':0,'No internet service':0})
    df['OnlineBackup'] = df.OnlineBackup.map({'Yes':1,'No':0,'No internet service':0})
    df['DeviceProtection'] = df.DeviceProtection.map({'Yes':1,'No':0,'No internet service':0})
    df['TechSupport'] = df.TechSupport.map({'Yes':1,'No':0,'No internet service':0})
    df['StreamingTV'] = df.StreamingTV.map({'Yes':1,'No':0,'No internet service':0})
    df['StreamingMovies'] = df.StreamingMovies.map({'Yes':1,'No':0,'No internet service':0})

    df['IsContracted'] = df.ContractType.map({'One year':1,'Two year':1,'Month-to-month':0})
    df['PaperlessBilling'] = df.PaperlessBilling.map({'Yes':1,'No':0})
    df['Churn'] = df.Churn.map({'Yes':1,'No':0})

    df.loc[df['TotalCharges']==' ','TotalCharges'] = np.nan
    df['TotalCharges'] = df['TotalCharges'].astype('float64')
    df.loc[df['TotalCharges']==np.nan,'TotalCharges'] = df['MonthlyCharges'] * df['Tenure']

    return df

clean_df = shuffle(clean_data(df_raw.copy())).reset_index()
clean_df.head()

categorical_vars = ['Gender','InternetServiceType','PaymentMethod','ContractType']
binary_vars = ['SeniorCitizen','Partner','Dependents','PhoneService','MultipleLines','OnlineSecurity','OnlineBackup'
               ,'DeviceProtection','TechSupport','StreamingTV', 'StreamingMovies','PaperlessBilling','InternetService'
               , 'IsContracted']
numeric_vars = ['Tenure','MonthlyCharges']
target_var = 'Churn'

def one_hot_encoding_features_df(df, cat_feat):
    cat_df = pd.get_dummies(df[cat_feat])
    return cat_df

def merge_df(categorical=None,binary=None,numerical=None):
    return pd.concat([categorical,binary,numerical],axis = 1)

feature_df = merge_df(one_hot_encoding_features_df(clean_df,categorical_vars), clean_df[binary_vars] ,clean_df[numeric_vars])
target_df = clean_df[target_var]

def train_test_split_fn(feature, target , test_size=None, random_state=0):
    return train_test_split(feature, target, test_size = test_size,random_state = random_state )

x_train, x_test, y_train , y_test = train_test_split_fn(feature_df,target_df,0.2,42)

###
RF_model = RandomForestClassifier(oob_score = True, random_state = 42)
RF_model.fit(x_train,y_train)
print("###################################################")
print('RandomForest')
print("OOB score", RF_model.oob_score_)
rf_result = cross_val_score(RF_model, x_train, y_train, scoring = 'accuracy')
print(rf_result.mean())
predicted = np.argmax(RF_model.oob_decision_function_, axis = 1)
metrics.roc_auc_score(y_train, predicted)
#
x_train_sm , y_train_sm = SMOTE(random_state = 42, sampling_strategy = 'auto').fit_resample(x_train,y_train)
RF_model_1 = RandomForestClassifier(oob_score = True, random_state = 42)
RF_model_1.fit(x_train_sm, y_train_sm)
print("###################################################")
print('SMOTE_RandomForest')
print("OOB score", RF_model_1.oob_score_)
rf_result_1 = cross_val_score(RF_model_1, x_train_sm, y_train_sm, scoring = 'accuracy')
print(rf_result_1.mean())
predicted_1 = np.argmax(RF_model_1.oob_decision_function_, axis = 1)
metrics.roc_auc_score(y_train_sm, predicted_1)

###
max_depth_size = [1,2,3,4,5,7,10,15,20]
train_roc_score = []
test_roc_score = []
print("###################################################")
print('analysis_depth')
for depth in max_depth_size:
    model = RandomForestClassifier(oob_score = True, random_state = 42, max_depth = depth)
    model.fit(x_train_sm, y_train_sm)
    train_pred = model.predict(x_train_sm)
    test_pred = model.predict(x_test)
    roc_auc_train = metrics.roc_auc_score(y_train_sm, train_pred)
    roc_auc_test = metrics.roc_auc_score(y_test, test_pred)
    train_roc_score.append(roc_auc_train)
    test_roc_score.append(roc_auc_test)
    print("Max depth size", depth)
    print("Train AUC ROC score ", roc_auc_train)
    print("Test AUC ROC score ", roc_auc_test)
plt.plot(max_depth_size, train_roc_score)
plt.plot(max_depth_size, test_roc_score)

###
n_estimator_size = [1,5,10,20,50,70,100,150,200,500,1000]
train_roc_score = []
test_roc_score = []
print("###################################################")
print('analysis_estimator')
for estimator in n_estimator_size:
    model = RandomForestClassifier(estimator, random_state = 42, oob_score = True, max_depth = 5)
    model.fit(x_train_sm, y_train_sm)
    train_pred = model.predict(x_train_sm)
    test_pred = model.predict(x_test)
    roc_auc_train = metrics.roc_auc_score(y_train_sm, train_pred)
    roc_auc_test = metrics.roc_auc_score(y_test, test_pred)
    train_roc_score.append(roc_auc_train)
    test_roc_score.append(roc_auc_test)
    print("No of trees", estimator)
    print("Train AUC ROC Score", roc_auc_train)
    print("Test AUC ROC Score", roc_auc_test)
plt.plot(n_estimator_size, train_roc_score)
plt.plot(n_estimator_size, test_roc_score)

###
max_features = ['sqrt', None, 'sqrt','log2',0.7,0.2]
oob_score = []
print("###################################################")
print('analysis_feature')
for feature in max_features:
    model = RandomForestClassifier( n_estimators = 200, oob_score = True, random_state = 42 ,  max_depth = 5, max_features = feature)
    model.fit(x_train_sm, y_train_sm)
    oob_score.append(model.oob_score_)
    print("Max features", feature)
    print("OOB Score", model.oob_score_)
###
min_sample_leaf = [1,2,3,4,5,10,15,20,50]
oob_score = []
print("###################################################")
print('analysis_leaf')
for sample in min_sample_leaf:
    model = RandomForestClassifier(n_estimators = 200, oob_score = True, random_state = 42, max_depth = 5, min_samples_leaf = sample
                                  , max_features = 'sqrt')
    model.fit(x_train_sm, y_train_sm)
    oob_score.append(model.oob_score_)
    print("min_sample_leaf", sample)
    print("OOB Score", model.oob_score_)
plt.plot(min_sample_leaf, oob_score)

###
RF_model_final = RandomForestClassifier(n_estimators = 5, random_state = 42, max_depth = 5)
RF_model_final.fit(x_train_sm,y_train_sm)
RF_model_final.estimators_
predicted = RF_model_final.predict(x_test)
metrics.confusion_matrix(y_test,predicted)
metrics.confusion_matrix(y_test,predicted)
print("###################################################")
print(metrics.classification_report(y_test,predicted))

###
metrics.roc_auc_score(y_test,predicted)
feature_importances = pd.Series(RF_model_final.feature_importances_,index = x_train.columns)
plt.figure(figsize=(10,8))
feature_importances.sort_values().plot(kind='barh')

###
selected_features = clean_df[['PaymentMethod','ContractType','InternetServiceType','OnlineSecurity','Tenure','MonthlyCharges','Churn']].copy()
selected_features['Payment_Electronic_Check'] = clean_df.PaymentMethod.map({'Electronic check':1,
                                                                            'Credit card (automatic)':0,
                                                                            'Bank transfer (automatic)':0,
                                                                            'Mailed check':0 }
                                                                           )
selected_features['Internet_Fiber_Optic'] = clean_df.InternetServiceType.map({'Fiber optic':1,
                                                                              'DSL':0,
                                                                              'No':0}
                                                                             )
selected_features.head()
selected_feature_df = merge_df(one_hot_encoding_features_df(selected_features,['ContractType']),selected_features[['Payment_Electronic_Check',
                                                                                                                   'Internet_Fiber_Optic',
                                                                                                                   'OnlineSecurity']], numerical = selected_features[['Tenure','MonthlyCharges']])
selected_target_df = clean_df[target_var]
feat_x_train, feat_x_test, feat_y_train , feat_y_test = train_test_split_fn(selected_feature_df,selected_target_df,0.2,42)
feat_x_train_sm , feat_y_train_sm = SMOTE(random_state = 42, sampling_strategy = 'auto').fit_resample(feat_x_train,feat_y_train)
RF_model_final = RandomForestClassifier(n_estimators = 1000, random_state = 42, max_depth = 7,class_weight = 'balanced')
RF_model_final.fit(feat_x_train,feat_y_train)
predicted = RF_model_final.predict(feat_x_test)
metrics.confusion_matrix(feat_y_test,predicted)
print(metrics.classification_report(feat_y_test,predicted))
metrics.roc_auc_score(feat_y_test,predicted)
# ROC curve
fpr, tpr, thresold = metrics.roc_curve(feat_y_test, RF_model_final.predict_proba(feat_x_test)[:][:,1])
plt.plot(fpr,tpr , label = 'Random Forest (area: %0.2f)' % metrics.roc_auc_score(feat_y_test,predicted))
plt.plot([0,1],[0,1],label = 'Base rate')
plt.xlabel("False postive rate")
plt.ylabel("True postive rate")
plt.title("ROC curve")
plt.legend()
rf_result_1 = cross_val_score(RF_model_final, feat_x_train, feat_y_train,cv=5, scoring = 'accuracy')
print(rf_result_1.mean())
rf_result_1

#plt.show()