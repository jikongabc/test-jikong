import matplotlib.pyplot as plt
import numpy as np
# 编码设置，确保能正确显示中文字符
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 数据
categories = ['粮食作物', '蔬菜', '食用菌', '豆类作物']
yields = [735, 4670, 5000, 1337]  # 平均亩产量
costs = [537, 2292, 6250, 965]  # 平均种植成本

# 创建条形图
fig, ax = plt.subplots(figsize=(10, 6))

bar_width = 0.35
index = np.arange(len(categories))

# 创建亩产量和种植成本的条形图，指定颜色并调整透明度
bar1 = ax.bar(index, yields, bar_width, label='平均亩产量 (斤)', color='orange', alpha=0.7)
bar2 = ax.bar(index + bar_width, costs, bar_width, label='平均种植成本 (元/亩)', color='darkorange', alpha=1)

# 设置标签和标题
ax.set_xlabel('类别')
ax.set_ylabel('值')
ax.set_title('作物的平均亩产量与平均种植成本对比')
ax.set_xticks(index + bar_width / 2)
ax.set_xticklabels(categories)
ax.legend()

# 显示条形图
plt.tight_layout()
plt.show()