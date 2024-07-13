import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 读取数据
data = pd.read_excel('C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx') # 请根据实际路径调整文件名

# 统计每列的缺失值数量
missing_values = data.isnull().sum()

# 生成条形图
plt.figure(figsize=(12, 6))
sns.barplot(x=missing_values.index, y=missing_values.values, palette='viridis')
plt.title('缺失值数量条形图')
plt.xlabel('参数')
plt.ylabel('缺失值')
plt.xticks(rotation=45)
plt.show()
