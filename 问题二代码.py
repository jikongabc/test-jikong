import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

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

# 训练随机森林模型
rf = RandomForestRegressor(n_estimators=100, random_state=42)
rf.fit(X_train, y_train)

# 定义超参数网格
param_grid = {
    'n_estimators': [50, 100, 200],
    'max_depth': [None, 10, 20, 30],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4]
}

# 进行网格搜索，将 n_jobs 设置为 1
grid_search = GridSearchCV(estimator=rf, param_grid=param_grid, cv=5, n_jobs=1, scoring='r2')
grid_search.fit(X_train, y_train)

# 获取最佳模型
best_rf = grid_search.best_estimator_
print("最佳模型参数: ", grid_search.best_params_)

# 预测测试集
y_pred = best_rf.predict(X_test)

# 计算评估指标
mse = mean_squared_error(y_test, y_pred)
mae = mean_absolute_error

# 绘制实际值与预测值的对比折线图
plt.figure(figsize=(12, 6))
plt.plot(y_test.values, label='实际值')
plt.plot(y_pred, label='预测值')
plt.xlabel('样本指数')
plt.ylabel('硬度')
plt.title('实际值与预测值')
plt.legend()
plt.show()
# 绘制特征重要性
importances = best_rf.feature_importances_
indices = np.argsort(importances)[::-1]
plt.figure(figsize=(12, 6))
plt.title("特征重要性")
plt.bar(range(X.shape[1]), importances[indices], align="center")
plt.xticks(range(X.shape[1]), [selected_features[i] for i in indices], rotation=90)
plt.xlim([-1, X.shape[1]])
plt.show()