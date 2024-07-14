import os
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split, GridSearchCV, RandomizedSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestRegressor

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 设置临时目录
os.environ['TMP'] = 'C:\\temp'
os.environ['TEMP'] = 'C:\\temp'

# 读取处理后的数据
file_path = 'D:/ae/222.xlsx'  # 确保文件路径正确
data = pd.read_excel(file_path)

# 数据预处理
data = data.apply(pd.to_numeric, errors='coerce')
data = data.dropna()

# 选择特征和目标变量
selected_features = ['x3', 'x6', 'x7', 'x9', 'x10', 'x11']
target = 'y'

X = data[selected_features]
y = data[target]

# 数据标准化
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 划分训练集和测试集，使用80/20比例
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

# 训练基础模型（未优化）
rf = RandomForestRegressor(random_state=42)
rf.fit(X_train, y_train)
y_pred_basic = rf.predict(X_test)

# 计算基础模型的评估指标
mse_basic = mean_squared_error(y_test, y_pred_basic)
mae_basic = mean_absolute_error(y_test, y_pred_basic)
r2_basic = r2_score(y_test, y_pred_basic)

print(f"未优化模型 - MSE: {mse_basic}, MAE: {mae_basic}, R²: {r2_basic}")

# 定义超参数网格
param_grid = {
    'n_estimators': [50, 100, 200],
    'max_depth': [None, 10, 20, 30],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4]
}

# 网格搜索
grid_search = GridSearchCV(estimator=rf, param_grid=param_grid, cv=5, n_jobs=1, scoring='r2')
grid_search.fit(X_train, y_train)

# 最佳模型
best_rf_grid = grid_search.best_estimator_
best_params_grid = grid_search.best_params_
print("最佳模型参数（网格搜索）: ", best_params_grid)

# 预测测试集
y_pred_grid = best_rf_grid.predict(X_test)

# 计算网格搜索优化模型的评估指标
mse_grid = mean_squared_error(y_test, y_pred_grid)
mae_grid = mean_absolute_error(y_test, y_pred_grid)
r2_grid = r2_score(y_test, y_pred_grid)

print(f"网格搜索优化模型 - MSE: {mse_grid}, MAE: {mae_grid}, R²: {r2_grid}")

# 定义超参数分布
param_dist = {
    'n_estimators': [50, 100, 200],
    'max_depth': [None, 10, 20, 30],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4]
}

# 随机搜索
random_search = RandomizedSearchCV(estimator=rf, param_distributions=param_dist, n_iter=100, cv=5, n_jobs=1, scoring='r2', random_state=42)
random_search.fit(X_train, y_train)

# 最佳模型
best_rf_random = random_search.best_estimator_
best_params_random = random_search.best_params_
print("最佳模型参数（随机搜索）: ", best_params_random)

# 预测测试集
y_pred_random = best_rf_random.predict(X_test)

# 计算随机搜索优化模型的评估指标
mse_random = mean_squared_error(y_test, y_pred_random)
mae_random = mean_absolute_error(y_test, y_pred_random)
r2_random = r2_score(y_test, y_pred_random)

print(f"随机搜索优化模型 - MSE: {mse_random}, MAE: {mae_random}, R²: {r2_random}")

# 绘制实际值与预测值的对比折线图（基础模型、网格搜索优化、随机搜索优化）
plt.figure(figsize=(12, 6))
plt.plot(y_test.values, label='实际值', marker='o')
plt.plot(y_pred_basic, label='基本预测值', marker='x')
plt.plot(y_pred_grid, label='网格搜索预测值', marker='s')
plt.plot(y_pred_random, label='随机搜索预测值', marker='d')
plt.xlabel('样本指数')
plt.ylabel('硬度')
plt.title('实际硬度和预测硬度 (基本搜索/网格搜索/随机搜索)')
plt.legend()
plt.show()
