import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# 读取数据
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx' # 确保文件路径正确
data = pd.read_excel(file_path)

# 转换数据类型
data = data.apply(pd.to_numeric, errors='coerce')
data = data.dropna()

# 变量列表
variables = ['x1', 'x2', 'x3', 'x4', 'x5']
for var in variables:
     plt.figure(figsize=(10, 6))
     sns.scatterplot(x=data[var], y=data['y'])
     plt.title(f'{var} vs y')
     plt.xlabel(var)
     plt.ylabel('y')
     plt.show()
