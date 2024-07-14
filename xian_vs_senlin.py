import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
import pandas as pd
import numpy as np

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 读取数据
data = pd.read_excel('C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/222.xlsx')

# 转换数据类型
for column in data.columns:
    data[column] = pd.to_numeric(data[column], errors='coerce')

# 处理缺失值：这里我们选择删除包含缺失值的行
data_cleaned = data.dropna()

# 特征和标签
X = data_cleaned.drop(columns='y')
y = data_cleaned['y']

# 分割数据集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 线性回归模型
model_lr = LinearRegression()
model_lr.fit(X_train, y_train)
y_pred_lr = model_lr.predict(X_test)
mse_lr = mean_squared_error(y_test, y_pred_lr)
r2_lr = r2_score(y_test, y_pred_lr)
mae_lr = np.mean(np.abs(y_test - y_pred_lr))

# 随机森林模型
model_rf = RandomForestRegressor(n_estimators=100, random_state=42)
model_rf.fit(X_train, y_train)
y_pred_rf = model_rf.predict(X_test)
mse_rf = mean_squared_error(y_test, y_pred_rf)
r2_rf = r2_score(y_test, y_pred_rf)
mae_rf = np.mean(np.abs(y_test - y_pred_rf))

# 打印评估指标
print(f"Linear Regression - MSE: {mse_lr}, MAE: {mae_lr}, R2: {r2_lr}")
print(f"Random Forest - MSE: {mse_rf}, MAE: {mae_rf}, R2: {r2_rf}")

# 可视化结果
plt.figure(figsize=(14, 6))

# 线性回归结果
plt.subplot(1, 2, 1)
plt.scatter(y_test, y_pred_lr, alpha=0.5)
plt.plot([y.min(), y.max()], [y.min(), y.max()], 'r--', lw=2)
plt.xlabel('实际值')
plt.ylabel('预测值')
plt.title(f'线性回归\nMSE: {mse_lr:.2f}, MAE: {mae_lr:.2f}, R2: {r2_lr:.2f}')

# 随机森林结果
plt.subplot(1, 2, 2)
plt.scatter(y_test, y_pred_rf, alpha=0.5)
plt.plot([y.min(), y.max()], [y.min(), y.max()], 'r--', lw=2)
plt.xlabel('实际值')
plt.ylabel('预测值')
plt.title(f'随机森林\nMSE: {mse_rf:.2f}, MAE: {mae_rf:.2f}, R2: {r2_rf:.2f}')

plt.tight_layout()
plt.show()
