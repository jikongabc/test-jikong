import pandas as pd
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression  # 修改了这一行
from sklearn.model_selection import train_test_split, GridSearchCV, \
    StratifiedKFold, cross_val_predict
from sklearn.metrics import roc_auc_score, recall_score, precision_score, \
    f1_score
from sklearn.preprocessing import StandardScaler, LabelEncoder
from lightgbm import LGBMClassifier
from sklearn.ensemble import StackingClassifier
from joblib import parallel_backend
import numpy as np
import os


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

# 处理缺失值（这里以中位数填充为例，可以根据实际情况调整）
for col in train_data.columns:
    if train_data[col].dtype == 'object':
        le = LabelEncoder()
        train_data[col] = le.fit_transform(train_data[col].astype(str))
        if col in test_data.columns:
            test_data[col] = test_data[col].astype(str)  # 确保类型一致
            unseen_labels = set(test_data[col]) - set(le.classes_)
            if unseen_labels:
                # 为未见过的类别标签添加一个特殊类别，如 "unseen"
                le.classes_ = np.append(le.classes_, "unseen")
                test_data[col] = test_data[col].apply(
                    lambda x: x if x in le.classes_ else "unseen")
            test_data[col] = le.transform(test_data[col])
    else:
        train_data[col].fillna(train_data[col].median(), inplace=True)
        if col in test_data.columns:
            test_data[col].fillna(train_data[col].median(), inplace=True)

# 分离特征和目标变量
X = train_data.drop(columns=['target'])
y = train_data['target']

# 确保所有数据都是数值型
X = pd.get_dummies(X)
test_data = pd.get_dummies(test_data)

# 对齐训练集和测试集中的列，缺失的列用0填补
X, test_data = X.align(test_data, join='left', axis=1)
test_data = test_data.fillna(0)

# 标准化数据
scaler = StandardScaler()
X = scaler.fit_transform(X)
test_data = scaler.transform(test_data)

# 使用 StratifiedKFold 来确保数据平衡
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

# 定义模型和参数
models = {
    'RandomForest': RandomForestClassifier(random_state=42),
    'GradientBoosting': GradientBoostingClassifier(random_state=42),
    'LogisticRegression': LogisticRegression(random_state=42, max_iter=1000),
    'LightGBM': LGBMClassifier(random_state=42)
}

# 更新的 LightGBM 参数
params = {
    'RandomForest': {
        'n_estimators': [50, 100],
        'max_depth': [None, 10],
        'min_samples_split': [2, 5]
    },
    'GradientBoosting': {
        'n_estimators': [50, 100],
        'learning_rate': [0.01, 0.1],
        'max_depth': [3, 5]
    },
    'LogisticRegression': {
        'C': [0.1, 1, 10]
    },
    'LightGBM': {
        'n_estimators': [50, 100],
        'learning_rate': [0.01, 0.1],
        'max_depth': [3, 5],
        'min_split_gain': [0.0, 0.01],
        'min_child_samples': [5, 10],
        'force_col_wise': [True]
    }
}

# 进行超参数搜索和模型评估
best_models = {}
best_scores = {}
for name, model in models.items():
    print(f"Training {name}...")
    with parallel_backend('threading'):
        grid_search = GridSearchCV(model, params[name], cv=cv,
                                   scoring='roc_auc', n_jobs=2)
        grid_search.fit(X, y)
    best_models[name] = grid_search.best_estimator_
    best_scores[name] = grid_search.best_score_

    # 使用交叉验证进行预测
    val_pred_proba = cross_val_predict(grid_search.best_estimator_, X, y, cv=cv,
                                       method='predict_proba')[:, 1]
    val_auc = roc_auc_score(y, val_pred_proba)
    val_recall = recall_score(y, (val_pred_proba > 0.5).astype(int))
    val_precision = precision_score(y, (val_pred_proba > 0.5).astype(int))
    val_f1 = f1_score(y, (val_pred_proba > 0.5).astype(int))

    print(f"{name} Validation AUC: {val_auc}")
    print(f"{name} Validation Recall: {val_recall}")
    print(f"{name} Validation Precision: {val_precision}")
    print(f"{name} Validation F1 Score: {val_f1}")
    print(f"Best parameters for {name}: {grid_search.best_params_}")

# 选择最佳模型并在测试集上进行预测
best_model_name = max(best_scores, key=best_scores.get)
best_model = best_models[best_model_name]
print(f"Best model: {best_model_name}")

# 集成多个模型（如Stacking）
estimators = [(name, model) for name, model in best_models.items()]
stacked_model = StackingClassifier(estimators=estimators,
                                   final_estimator=LogisticRegression(), cv=cv)
stacked_model.fit(X, y)

# 在测试集上进行预测
test_pred_proba = stacked_model.predict_proba(test_data)[:, 1]
test_pred = stacked_model.predict(test_data)

# 读取提交模板
submit_template = pd.read_csv(submit_template_path, encoding='latin1')

# 将预测结果写入提交模板
submit_template['proba'] = test_pred_proba
submit_template['prediction'] = test_pred

# 保存预测结果
submit_template.to_csv(r"C:\Users\罗祥\Desktop\新建文件夹 (2)\submit(4).csv",
                       index=False)
