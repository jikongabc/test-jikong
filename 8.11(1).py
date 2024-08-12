import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier, StackingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split, GridSearchCV, StratifiedKFold, cross_val_predict
from sklearn.metrics import roc_auc_score, recall_score, precision_score, f1_score
from sklearn.preprocessing import StandardScaler, OrdinalEncoder, PolynomialFeatures
from sklearn.pipeline import Pipeline
from lightgbm import LGBMClassifier
from sklearn.base import BaseEstimator, TransformerMixin

# 自定义的特征工程步骤
class FeatureEngineering(BaseEstimator, TransformerMixin):
    def __init__(self):
        pass
    
    def fit(self, X, y=None):
        return self
    
    def transform(self, X):
        # 添加特征交互项
        poly = PolynomialFeatures(degree=2, interaction_only=True, include_bias=False)
        X_poly = poly.fit_transform(X)
        X_poly_df = pd.DataFrame(X_poly, columns=poly.get_feature_names_out(X.columns))
        
        # 将原始特征和交互特征合并
        X = pd.concat([X.reset_index(drop=True), X_poly_df.reset_index(drop=True)], axis=1)
        
        return X

# 读取数据
train_data_path = r"C:\Users\罗祥\Desktop\新建文件夹 (2)\train_data_cleaned(2).csv"
test_data_path = r"C:\Users\罗祥\Desktop\新建文件夹 (2)\test_data_cleaned.csv"

train_data = pd.read_csv(train_data_path, encoding='latin1')
test_data = pd.read_csv(test_data_path, encoding='latin1')

# 处理缺失值（这里以填充0为例，可以根据实际情况调整）
train_data = train_data.fillna(0)
test_data = test_data.fillna(0)

# 分离特征和目标变量
X = train_data.drop(columns=['target'])
y = train_data['target']

# 确保所有类别列都是字符串类型
for col in X.select_dtypes(include=['object', 'category']).columns:
    X[col] = X[col].astype(str)
    test_data[col] = test_data[col].astype(str)

# 类别编码使用 OrdinalEncoder
oe = OrdinalEncoder(handle_unknown='use_encoded_value', unknown_value=-1)
X[X.select_dtypes(include='object').columns] = oe.fit_transform(X.select_dtypes(include='object'))
test_data[test_data.select_dtypes(include='object').columns] = oe.transform(test_data.select_dtypes(include='object'))

# 标准化数据
scaler = StandardScaler()
X = scaler.fit_transform(X)
test_data = scaler.transform(test_data)

# 特征工程和模型集成
feature_engineering = FeatureEngineering()

# 定义模型
base_models = [
    ('rf', RandomForestClassifier(n_estimators=100, random_state=42)),
    ('gbc', GradientBoostingClassifier(n_estimators=100, random_state=42)),
    ('lgbm', LGBMClassifier(n_estimators=100, learning_rate=0.1, random_state=42))
]

# Stacking集成模型
stacking_model = StackingClassifier(
    estimators=base_models,
    final_estimator=LogisticRegression(),
    cv=5
)

# 建立管道
pipeline = Pipeline(steps=[
    ('feature_engineering', feature_engineering),
    ('model', stacking_model)
])

# 交叉验证设置
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

# 超参数调优
param_grid = {
    'model__lgbm__learning_rate': [0.01, 0.05, 0.1],
    'model__lgbm__n_estimators': [100, 200],
    'model__gbc__learning_rate': [0.01, 0.1],
    'model__gbc__n_estimators': [100, 200],
    'model__rf__n_estimators': [100, 200],
}

grid_search = GridSearchCV(pipeline, param_grid, cv=cv, scoring='roc_auc', n_jobs=-1)
grid_search.fit(X, y)

# 输出最优参数
print("Best parameters found:", grid_search.best_params_)

# 用最优模型对测试集进行预测
best_model = grid_search.best_estimator_
test_pred_proba = best_model.predict_proba(test_data)[:, 1]

# 假设你有一个提交模板
submit_template = pd.DataFrame()
submit_template['uuid'] = test_data['uuid']  # 替换为你数据集中的唯一标识符
submit_template['proba'] = test_pred_proba

# 保存提交文件
submit_template.to_csv(r"C:\Users\罗祥\Desktop\新建文件夹 (2)\submit(4).csv", index=False)

# 评估指标
def evaluate_model(model, X, y, cv):
    pred_proba = cross_val_predict(model, X, y, cv=cv, method='predict_proba')[:, 1]
    auc = roc_auc_score(y, pred_proba)
    recall = recall_score(y, pred_proba.round())
    precision = precision_score(y, pred_proba.round())
    f1 = f1_score(y, pred_proba.round())
    
    print(f"AUC: {auc:.4f}, Recall: {recall:.4f}, Precision: {precision:.4f}, F1 Score: {f1:.4f}")
    return auc, recall, precision, f1

# 在训练集上评估模型
evaluate_model(best_model, X, y, cv)
