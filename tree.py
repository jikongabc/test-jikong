import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.tree import DecisionTreeRegressor
from sklearn import tree
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号


# 读取处理后的数据
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/222.xlsx'  #
# 确保文件路径正确
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

# 训练决策树模型
dt = DecisionTreeRegressor(random_state=42)
dt.fit(X_train, y_train)

# 绘制决策树
plt.figure(figsize=(20,10))
tree.plot_tree(dt, feature_names=selected_features, filled=True)
plt.title("决策树")
plt.show()