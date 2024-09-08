import pandas as pd
import numpy as np
from pulp import LpMaximize, LpProblem, LpVariable, lpSum, value

# 读取文件
land_data = pd.read_excel("./乡村的现有耕地.xlsx")  # 地块相关数据
crop_data = pd.read_excel("./2023年统计的相关数据.xlsx")  # 作物种植相关数据
crop_planting = pd.read_excel("./2023年的农作物种植情况.xlsx")  # 农作物种植情况
result1_1 = pd.read_excel("./result1_1.xlsx")
result1_2 = pd.read_excel("./result1_2.xlsx")

# 打印 crop_planting 的列名，检查是否有 '种植面积/亩' 列
print(crop_planting.columns)

# 清理缺失的作物名称
crop_planting = crop_planting.dropna(subset=['作物名称'])

# 地块信息
lands = land_data['地块名称']
land_area = dict(zip(land_data['地块名称'], land_data['地块面积/亩']))

# 作物信息
crops = crop_data['作物名称']
crop_yield = dict(zip(crop_data['作物名称'], crop_data['亩产量/斤']))
crop_cost = dict(zip(crop_data['作物名称'], crop_data['种植成本/(元/亩)']))

# 处理销售价格，提取区间的平均值，如果是浮点数则直接使用
def extract_avg_price(price):
    try:
        if isinstance(price, str):  # 如果价格是字符串区间
            low, high = map(float, price.split('-'))  # 提取上下限
            return (low + high) / 2  # 返回平均值
        return float(price)  # 如果是浮点数，直接返回
    except (ValueError, TypeError):
        return np.nan  # 遇到错误时返回 NaN

# 使用提取区间平均值的函数生成 crop_price
crop_price = {i: extract_avg_price(p) for i, p in zip(crop_data['作物名称'], crop_data['销售单价/(元/斤)'])}

# 移除包含 NaN 的作物，确保 crop_price、crop_yield 和 crop_cost 中没有 NaN 值
valid_crops = [i for i in crops if pd.notna(crop_price.get(i)) and pd.notna(crop_yield.get(i)) and pd.notna(crop_cost.get(i))]

# 计算2023年总产量 = 种植面积 * 亩产量
crop_planting['总产量'] = crop_planting['种植面积/亩'] * crop_planting['作物名称'].map(crop_yield)

# 确保没有缺失的作物名称
crop_planting = crop_planting.dropna(subset=['总产量'])

# 计算预期销售量的最大值 = 2023年的总产量
crop_max_sale = dict(zip(crop_planting['作物名称'], crop_planting['总产量']))

# 合理确定预期销售量的下界，假设为最大值的50%
crop_min_sale = {crop: max_sale * 0.5 for crop, max_sale in crop_max_sale.items()}

# 创建优化模型
model_1 = LpProblem(name="crop_optimization_case1", sense=LpMaximize)
model_2 = LpProblem(name="crop_optimization_case2", sense=LpMaximize)

# 决策变量: X[i,j] 表示在第 j 块地上种植 i 作物的面积
X = {(i, j): LpVariable(name=f"X_{i}_{j}", lowBound=0) for i in valid_crops for j in lands}

# 目标函数：最大化总利润（不考虑未来波动，只用2023年数据）
# Case 1: 超过部分滞销
model_1 += lpSum(X[i, j] * crop_price[i] * crop_yield[i] - X[i, j] * crop_cost[i] for i in valid_crops for j in lands)

# Case 2: 超过部分按50%价格出售
model_2 += lpSum(X[i, j] * crop_price[i] * crop_yield[i] - X[i, j] * crop_cost[i] for i in valid_crops for j in lands)

# 约束条件：每个地块的种植面积不能超过地块面积
for j in lands:
    model_1 += lpSum(X[i, j] for i in valid_crops) <= land_area[j], f"land_area_constraint_case1_{j}"
    model_2 += lpSum(X[i, j] for i in valid_crops) <= land_area[j], f"land_area_constraint_case2_{j}"

# 约束条件：每种作物的总产量不超过预期销售量的最大上界，不低于最小下界
for i in valid_crops:
    for j in lands:  # 为每个地块生成唯一约束名称，避免重复
        model_1 += lpSum(X[i, j] * crop_yield[i]) <= crop_max_sale[i], f"max_sale_constraint_case1_{i}_{j}"
        model_1 += lpSum(X[i, j] * crop_yield[i]) >= crop_min_sale[i], f"min_sale_constraint_case1_{i}_{j}"

        model_2 += lpSum(X[i, j] * crop_yield[i]) <= crop_max_sale[i], f"max_sale_constraint_case2_{i}_{j}"
        model_2 += lpSum(X[i, j] * crop_yield[i]) >= crop_min_sale[i], f"min_sale_constraint_case2_{i}_{j}"

# 特殊的轮作约束（例如豆类作物每三年轮作）
for j in lands:
    model_1 += lpSum(X[i, j] for i in ['黄豆', '绿豆'] if i in valid_crops) >= 1, f"bean_constraint_case1_{j}"
    model_2 += lpSum(X[i, j] for i in ['黄豆', '绿豆'] if i in valid_crops) >= 1, f"bean_constraint_case2_{j}"

# 求解模型
model_1.solve()
model_2.solve()

# 提取求解结果并保存到变量
optimal_planting_case1 = {(i, j): X[i, j].varValue for i in valid_crops for j in lands}
optimal_planting_case2 = {(i, j): X[i, j].varValue for i in valid_crops for j in lands}

# 输出结果
print("----Case 1: 超过部分滞销----")
for v in model_1.variables():
    print(f"{v.name} = {v.value()}")

print(f"Total profit for Case 1: {value(model_1.objective)}")

print("----Case 2: 超过部分按50%价格出售----")
for v in model_2.variables():
    print(f"{v.name} = {v.value()}")

print(f"Total profit for Case 2: {value(model_2.objective)}")

# 填充result1_1.xlsx for Case 1
for (i, j), area in optimal_planting_case1.items():
    if i in result1_1.columns:
        result1_1.loc[result1_1["地块名"] == j, i] = area

# 填充result1_2.xlsx for Case 2
for (i, j), area in optimal_planting_case2.items():
    if i in result1_2.columns:
        result1_2.loc[result1_2["地块名"] == j, i] = area

# 保存结果到Excel文件
result1_1.to_excel('./result1_1.xlsx', index=False)
result1_2.to_excel('./result1_2.xlsx', index=False)

print("结果已成功写入 filled_result1_1.xlsx 和 filled_result1_2.xlsx")
