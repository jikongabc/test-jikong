
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用SimHei字体
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号
# 读取Excel文件并提取最后三列
file_path = '附件2-2清洗后数据.xlsx'
df = pd.read_excel(file_path)

# 选择相关列#
columns_of_interest = ['亩产量/斤', '种植成本/(元/亩)', '销售单价/(元/斤)']
df_selected = df[columns_of_interest]

# 检查数据是否有缺失值并进行处理
df_selected = df_selected.dropna()

# Step 1: 计算三者之间的相关性矩阵
correlation_matrix = df_selected.corr()

# 可视化相关性矩阵
plt.figure(figsize=(8, 6))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', linewidths=0.5)
plt.title('Correlation Matrix of 亩产量, 种植成本, and 销售单价')
plt.show()

# Step 2: 进行多元线性回归分析，建立亩产量与种植成本、销售单价之间的关系模型

# 定义特征和目标变量
X = df_selected[['种植成本/(元/亩)', '销售单价/(元/斤)']]
y = df_selected['亩产量/斤']

# 拆分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 创建并训练线性回归模型
model = LinearRegression()
model.fit(X_train, y_train)

# 预测测试集
y_pred = model.predict(X_test)

# 输出模型参数和评估指标
print(f"模型系数: {model.coef_}")
print(f"截距: {model.intercept_}")
print(f"均方误差(MSE): {mean_squared_error(y_test, y_pred)}")
print(f"R²: {r2_score(y_test, y_pred)}")

# 可视化真实值与预测值的对比
plt.figure(figsize=(8, 6))
plt.scatter(y_test, y_pred, color='blue')
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'k--', lw=2, color='red')#
plt.xlabel('真实值')
plt.ylabel('预测值')
plt.title('亩产量的真实值与预测值对比')
plt.show()

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.font_manager as fm

# 设置支持中文的字体（例如 SimHei），确保系统中安装了该字体
# 如果没有安装SimHei，可以选择其他支持中文的字体，如 'Microsoft YaHei'
plt.rcParams['font.family'] = 'SimHei'  # 替换为系统中可用的中文字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号 '-' 显示为方块的问题

# 读取Excel文件
file_path = '附件2-2清洗后数据.xlsx'  # 请将此路径替换为实际文件路径
df = pd.read_excel(file_path)

# 提取相关列
columns_of_interest = ['亩产量/斤', '种植成本/(元/亩)', '销售单价/(元/斤)']
df_selected = df[columns_of_interest]

# 检查缺失值并移除#
df_selected = df_selected.dropna()

# 查看数据基本情况
print("数据描述统计：")
print(df_selected.describe())

# 关系1: 销售单价/(元/斤) = f(种植成本/(元/亩))
X_price = df_selected[['种植成本/(元/亩)']]
y_price = df_selected['销售单价/(元/斤)']

# 拆分训练集和测试集
X_train_price, X_test_price, y_train_price, y_test_price = train_test_split(
    X_price, y_price, test_size=0.2, random_state=42
)

# 创建并训练线性回归模型
model_price = LinearRegression()
model_price.fit(X_train_price, y_train_price)

# 预测测试集
y_pred_price = model_price.predict(X_test_price)

# 输出模型参数和评估指标
print("\n销售单价/(元/斤) = {:.4f} + {:.4f} * 种植成本/(元/亩)".format(#
    model_price.intercept_, model_price.coef_[0]
))
print(f"销售单价模型均方误差(MSE): {mean_squared_error(y_test_price, y_pred_price):.4f}")
print(f"销售单价模型R²: {r2_score(y_test_price, y_pred_price):.4f}")

# 可视化销售单价回归
plt.figure(figsize=(8, 6))
sns.scatterplot(x=X_test_price['种植成本/(元/亩)'], y=y_test_price, label='真实值')
sns.scatterplot(x=X_test_price['种植成本/(元/亩)'], y=y_pred_price, label='预测值', marker='x')
plt.plot(X_test_price['种植成本/(元/亩)'], model_price.predict(X_test_price), color='red', label='回归线')
plt.xlabel('种植成本/(元/亩)')
plt.ylabel('销售单价/(元/斤)')
plt.title('销售单价与种植成本的回归分析')
plt.legend()
plt.show()

# 关系2: 亩产量/斤 = f(种植成本/(元/亩))
X_yield = df_selected[['种植成本/(元/亩)']]
y_yield = df_selected['亩产量/斤']

# 拆分训练集和测试集
X_train_yield, X_test_yield, y_train_yield, y_test_yield = train_test_split(
    X_yield, y_yield, test_size=0.2, random_state=42
)

# 创建并训练线性回归模型
model_yield = LinearRegression()
model_yield.fit(X_train_yield, y_train_yield)

# 预测测试集
y_pred_yield = model_yield.predict(X_test_yield)

# 输出模型参数和评估指标
print("\n亩产量/斤 = {:.4f} + {:.4f} * 种植成本/(元/亩)".format(
    model_yield.intercept_, model_yield.coef_[0]
))
print(f"亩产量模型均方误差(MSE): {mean_squared_error(y_test_yield, y_pred_yield):.4f}")
print(f"亩产量模型R²: {r2_score(y_test_yield, y_pred_yield):.4f}")

# 可视化亩产量回归
plt.figure(figsize=(8, 6))
sns.scatterplot(x=X_test_yield['种植成本/(元/亩)'], y=y_test_yield, label='真实值')
sns.scatterplot(x=X_test_yield['种植成本/(元/亩)'], y=y_pred_yield, label='预测值', marker='x')
plt.plot(X_test_yield['种植成本/(元/亩)'], model_yield.predict(X_test_yield), color='red', label='回归线')
plt.xlabel('种植成本/(元/亩)')
plt.ylabel('亩产量/斤')
plt.title('亩产量与种植成本的回归分析')
plt.legend()
plt.show()
