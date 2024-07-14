# import pandas as pd
#
# # 读取数据
# file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'
# data = pd.read_excel(file_path)
#
# # 查看数据概况
# data.head()
# import seaborn as sns
# import matplotlib.pyplot as plt
#
# # 计算相关矩阵
# correlation_matrix = data.corr()
#
# # 绘制热力图
# plt.figure(figsize=(12, 8))
# sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', linewidths=0.5)
# plt.title('Correlation Matrix')
# plt.show()



# import pandas as pd
# import numpy as np
# import seaborn as sns
# import matplotlib.pyplot as plt
#
# # 使用本地文件路径C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx
# file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'
#
# # 读取数据
# data = pd.read_excel(file_path)
#
# # 查看数据概况
# print(data.head())
#
# # 检查数据框的信息
# print(data.info())
#
# # 删除全为 NaN 的列或行
# data = data.dropna(axis=1, how='all')  # 删除全为 NaN 的列
# data = data.dropna(axis=0, how='all')  # 删除全为 NaN 的行
#
# # 检查是否有数值列
# numeric_cols = data.select_dtypes(include=[np.number]).columns
# if len(numeric_cols) == 0:
#     raise ValueError("数据框中没有数值列，无法计算相关矩阵")
#
# # 计算相关矩阵
# correlation_matrix = data[numeric_cols].corr()
#
# # 绘制热力图
# plt.figure(figsize=(12, 8))
# sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', linewidths=0.5)
# plt.title('Correlation Matrix')
# plt.show()




# import pandas as pd
# import numpy as np
# import seaborn as sns
# import matplotlib.pyplot as plt
#
# # 使用本地文件路径
# file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'
#
# # 读取数据，跳过第一行
# data = pd.read_excel(file_path, skiprows=1)
#
# # 查看数据概况
# print(data.head())
#
# # 检查数据框的信息
# print(data.info())
#
# # 删除全为 NaN 的列或行
# data = data.dropna(axis=1, how='all')  # 删除全为 NaN 的列
# data = data.dropna(axis=0, how='all')  # 删除全为 NaN 的行
#
# # 转换数据类型
# for col in data.columns:
#     data[col] = pd.to_numeric(data[col], errors='coerce')
#
# # 删除无法转换为数值的列
# data = data.dropna(axis=1, how='all')
#
# # 检查是否有数值列
# numeric_cols = data.select_dtypes(include=[np.number]).columns
# if len(numeric_cols) == 0:
#     raise ValueError("数据框中没有数值列，无法计算相关矩阵")
#
# # 计算相关矩阵
# correlation_matrix = data[numeric_cols].corr()
#
# # 绘制热力图
# plt.figure(figsize=(12, 8))
# sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', linewidths=0.5)
# plt.title('Correlation Matrix')
# plt.show()




import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# 使用本地文件路径
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'

# 手动指定列名
column_names = ["x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "y"]

# 读取数据，跳过第一行
data = pd.read_excel(file_path, skiprows=1, header=None, names=column_names)

# 查看数据概况
print(data.head())

# 检查数据框的信息
print(data.info())

# 删除全为 NaN 的列或行
data = data.dropna(axis=1, how='all')  # 删除全为 NaN 的列
data = data.dropna(axis=0, how='all')  # 删除全为 NaN 的行

# 转换数据类型
for col in data.columns:
    data[col] = pd.to_numeric(data[col], errors='coerce')

# 删除无法转换为数值的列
data = data.dropna(axis=1, how='all')

# 检查是否有数值列
numeric_cols = data.select_dtypes(include=[np.number]).columns
if len(numeric_cols) == 0:
    raise ValueError("数据框中没有数值列，无法计算相关矩阵")

# 计算相关矩阵
correlation_matrix = data[numeric_cols].corr()

# 绘制热力图
plt.figure(figsize=(12, 8))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', linewidths=0.5)
plt.title('相关因素指标的pearson热力图')
plt.show()

