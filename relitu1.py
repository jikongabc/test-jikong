import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

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

# 计算相关矩阵
correlation_matrix = data_cleaned.corr()

# 绘制相关性矩阵热力图
plt.figure(figsize=(12, 8))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt='.2f')
plt.title('相关因素指标的pearson热力图')
plt.show()