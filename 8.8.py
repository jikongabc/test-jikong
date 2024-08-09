import pandas as pd
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import roc_auc_score, recall_score, precision_score
from sklearn.preprocessing import StandardScaler
import lightgbm as lgb
import xgboost as xgb
import os
from tempfile import gettempdir
from sklearn.utils import parallel_backend

# 创建一个临时文件夹路径
joblib_temp_folder = r"C:\temp_joblib"
if not os.path.exists(joblib_temp_folder):
    os.makedirs(joblib_temp_folder)

# 设置joblib的临时文件夹路径
os.environ['JOBLIB_TEMP_FOLDER'] = joblib_temp_folder

# 读取清洗后的训练数据和测试数据
train_data_path = r"C:\Users\罗祥\Desktop\新建文件夹 (2)\train_data_cleaned(2).csv"
test_data_path = r"C:\Users\罗祥\Desktop\新建文件夹 (2)\test_data_cleaned.csv"
submit_template_path = r"C:\Users\罗祥\Desktop\新建文件夹 (2)\submit(4).csv"

train_data = pd.read_csv(train_data_path, encoding='latin1')
test_data = pd.read_csv(test_data_path, encoding='latin1')

# 处理缺失值
train_data = train_data.fillna(0)
test_data = test_data.fillna(0)

# 分离特征和目标变量
X = train_data.drop(columns=['target'])
y = train_data['target']

# 确保所有数据都是数值型，如果有非数值列，进行编码
X = pd.get_dummies(X)
test_data = pd.get_dummies(test_data)

# 对齐训练集和测试集中的列，缺失的列用0填补
X, test_data = X.align(test_data, join='inner', axis=1)

# 标准化数据
scaler = StandardScaler()
X = scaler.fit_transform(X)
test_data = scaler.transform(test_data)

# 拆分训练集和验证集
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

# 定义模型和参数
models = {
    'RandomForest': RandomForestClassifier(random_state=42),
    'GradientBoosting': GradientBoostingClassifier(random_state=42),
    'LogisticRegression': LogisticRegression(random_state=42, max_iter=1000),
    'LightGBM': lgb.LGBMClassifier(random_state=42),
    'XGBoost': xgb.XGBClassifier(random_state=42)
}

params = {
    'RandomForest': {
        'n_estimators': [50, 100, 200],
        'max_depth': [None, 10, 20],
        'min_samples_split': [2, 5, 10]
    },
    'GradientBoosting': {
        'n_estimators': [50, 100, 200],
        'learning_rate': [0.01, 0.1, 0.2],
        'max_depth': [3, 5, 7]
    },
    'LogisticRegression': {
        'C': [0.01, 0.1, 1, 10, 100]
    },
    'LightGBM': {
        'num_leaves': [31, 50, 100],
        'learning_rate': [0.01, 0.1, 0.2],
        'n_estimators': [50, 100, 200]
    },
    'XGBoost': {
        'n_estimators': [50, 100, 200],
        'learning_rate': [0.01, 0.1, 0.2],
        'max_depth': [3, 5, 7]
    }
}

# 进行超参数搜索和模型评估
best_models = {}
for name, model in models.items():
    print(f"Training {name}...")
    with parallel_backend('threading', n_jobs=2):  # 使用 threading 后端
        grid_search = GridSearchCV(model, params[name], cv=5, scoring='roc_auc', n_jobs=-1)
        grid_search.fit(X_train, y_train)
    best_models[name] = grid_search.best_estimator_
    val_pred_proba = grid_search.predict_proba(X_val)[:, 1]
    val_pred = grid_search.predict(X_val)
    val_auc = roc_auc_score(y_val, val_pred_proba)
    val_recall = recall_score(y_val, val_pred)
    val_precision = precision_score(y_val, val_pred)
    print(f"{name} Validation AUC: {val_auc}")
    print(f"{name} Validation Recall: {val_recall}")
    print(f"{name} Validation Precision: {val_precision}")
    print(f"Best parameters for {name}: {grid_search.best_params_}")

# 选择最佳模型
def model_score(model):
    val_pred_proba = model.predict_proba(X_val)[:, 1]
    val_pred = model.predict(X_val)
    auc = roc_auc_score(y_val, val_pred_proba)
    recall = recall_score(y_val, val_pred)
    precision = precision_score(y_val, val_pred)
    return 0.4 * auc + 0.4 * recall + 0.2 * precision

best_model_name = max(best_models, key=lambda name: model_score(best_models[name]))
best_model = best_models[best_model_name]
print(f"Best model: {best_model_name}")

# 在测试集上进行预测
test_pred_proba = best_model.predict_proba(test_data)[:, 1]
test_pred = best_model.predict(test_data)

# 读取提交模板
submit_template = pd.read_csv(submit_template_path, encoding='latin1')

# 将预测结果写入提交模板
submit_template['proba'] = test_pred_proba
submit_template['prediction'] = test_pred

# 保存预测结果
submit_template.to_csv(r"C:\Users\罗祥\Desktop\新建文件夹 (2)\submit(4).csv", index=False)
