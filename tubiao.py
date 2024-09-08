import matplotlib.pyplot as plt
# 编码设置，确保能正确显示中文字符
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 数据
categories = ['粮食作物', '蔬菜', '豆类作物', '食用菌']
total_production = [833490, 693028, 536137, 48000]  # 总产量
expected_sales = [583443, 485119.6, 375296, 33600]  # 预期销售量

# 创建折线图
plt.figure(figsize=(8, 6))

# 绘制总产量的折线
plt.plot(categories, total_production, marker='o', label='总产量/斤', color='blue', linestyle='-')

# 绘制预期销售量的折线
plt.plot(categories, expected_sales, marker='o', label='预期销售量/斤', color='green', linestyle='--')

# 设置标题和标签
plt.title('总产量与预期销售量(70%)对比')
plt.xlabel('类别')
plt.ylabel('数量（斤）')

# 显示图例
plt.legend()

# 显示图表
plt.grid(True)
plt.tight_layout()
plt.show()