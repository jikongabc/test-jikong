import pandas as pd
import numpy as np
from sklearn.linear_model import LassoCV
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 读取数据
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'
data = pd.read_excel(file_path)

# 处理缺失值并确保数据格式正确
data = data.apply(pd.to_numeric, errors='coerce')
data = data.fillna(data.mean())

# 提取特征和目标变量
X = data.drop(columns=['y'])  # 假设“y”是目标变量
y = data['y']

# 标准化特征数据
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 使用LASSO回归模型
lasso = LassoCV(cv=5).fit(X_scaled, y)

# 获取LASSO回归模型的系数
lasso_coef = pd.Series(lasso.coef_, index=X.columns)

# 绘制LASSO回归系数条形图
plt.figure(figsize=(12, 6))
lasso_coef.sort_values().plot(kind='bar')
plt.title('LASSO回归系数条形图')
plt.show()

# 打印LASSO模型选择的重要特征
important_features = lasso_coef[lasso_coef != 0].index.tolist()
print(f"Important features selected by LASSO: {important_features}")