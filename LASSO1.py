import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.linear_model import Lasso
from sklearn.preprocessing import StandardScaler

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 读取数据
data = pd.read_excel('C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx')

# 转换数据类型
for column in data.columns:
    data[column] = pd.to_numeric(data[column], errors='coerce')

# 处理缺失值：删除包含缺失值的行
data_cleaned = data.dropna()

# 特征和标签
X = data_cleaned.drop(columns='y')
y = data_cleaned['y']

# 标准化特征
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 训练LASSO回归模型
lasso = Lasso(alpha=0.1)
lasso.fit(X_scaled, y)

# 获取每个特征的回归系数
lasso_coefficients = lasso.coef_

# 将特征名称和系数组合为数据框
lasso_features = pd.DataFrame({
    'Feature': X.columns,
    'Coefficient': lasso_coefficients
})

# 过滤非零系数的特征
important_lasso_features = lasso_features[lasso_features['Coefficient'] != 0]

# 绘制LASSO回归模型的特征系数条形图
plt.figure(figsize=(12, 8))
sns.barplot(x='Coefficient', y='Feature', data=important_lasso_features, palette='coolwarm')
plt.title('LASSO回归系数条形图')
plt.xlabel('系数')
plt.ylabel('特征')
plt.show()