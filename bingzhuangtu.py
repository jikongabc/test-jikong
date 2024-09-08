#图一

# 作用：用于展示不同类型耕地的面积占比（如平旱地、梯田、山坡地和水浇地），帮助理解每类耕地的可用面积。
# 可以展示不同地块类型在乡村耕地中的分布情况，为优化种植方案提供依据。
import matplotlib.pyplot as plt
# 编码设置，确保能正确显示中文字符
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 数据
land_types = ['平旱地', '梯田', '智慧大棚', '山坡地', '水浇地', '普通大棚']
areas = [365, 619, 2.4, 108, 109, 9.6]

# 创建饼状图
plt.figure(figsize=(8, 6))
plt.pie(
    areas,
    labels=land_types,
    autopct='%1.1f%%',
    startangle=90,
    colors=['#ff9999','#66b3ff','#99ff99','#ffcc99', '#c2c2f0', '#ffb3e6'],
    textprops={'fontsize': 14}  # 设置标签和百分比的字体大小
)

# 确保饼状图为圆形
plt.axis('equal')

# 设置标题，调整位置使其稍微往上移
plt.title('地块面积分布', fontsize=16, pad=20)

# 显示图表
plt.show()


import matplotlib.pyplot as plt

# 编码设置，确保能正确显示中文字符
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 数据
land_types = ['平旱地', '梯田', '智慧大棚', '山坡地', '水浇地', '普通大棚']
areas = [365, 619, 2.4, 108, 109, 9.6]

# 创建饼状图
plt.figure(figsize=(8, 6))
wedges, texts, autotexts = plt.pie(
    areas,
    labels=land_types,
    autopct='%1.1f%%',
    startangle=90,
    colors=['#ff9999','#66b3ff','#99ff99','#ffcc99', '#c2c2f0', '#ffb3e6'],
    textprops={'fontsize': 14}  # 设置标签和百分比的字体大小
)

# 确保饼状图为圆形
plt.axis('equal')

# 设置标题，调整位置使其稍微往上移
plt.title('地块面积分布', fontsize=16, pad=20)

# 添加图例，放置在右侧
plt.legend(wedges, land_types, title="地块类型", loc="center left", bbox_to_anchor=(1, 0, 0.5, 1), fontsize=12)

# 显示图表
plt.tight_layout()
plt.show()


# 3D XXX
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
# import numpy as np
#
# # 编码设置，确保能正确显示中文字符
# plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
# plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号
#
# # 数据
# land_types = ['平旱地', '梯田', '智慧大棚', '山坡地', '水浇地', '普通大棚']
# areas = [365, 619, 2.4, 108, 109, 9.6]
#
# # 创建 3D 图形
# fig = plt.figure(figsize=(8, 6))
# ax = fig.add_subplot(1