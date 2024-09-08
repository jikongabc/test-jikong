import pandas as pd
from pulp import LpMaximize, LpProblem, LpVariable, lpSum, LpStatus
import warnings

# 忽略 openpyxl 的页眉和页脚解析警告
warnings.filterwarnings("ignore", category=UserWarning, module="openpyxl")

# 读取 Excel 文件
crop_data_2023 = pd.read_excel('./2023年的农作物种植情况.xlsx')
crop_data_stats = pd.read_excel('./2023年统计的相关数据.xlsx')
land_data_main = pd.read_excel('./乡村的现有耕地.xlsx')
land_data_crop = pd.read_excel('./乡村种植的农作物.xlsx')

# 合并作物数据和地块数据
merged_crop_data = pd.merge(crop_data_2023, crop_data_stats, on='作物名称', how='inner')
merged_land_data = pd.concat([land_data_main, land_data_crop], axis=0, ignore_index=True)

# 数据清理
merged_crop_data['种植面积/亩'] = pd.to_numeric(merged_crop_data['种植面积/亩'], errors='coerce')
merged_crop_data['亩产量/斤'] = pd.to_numeric(merged_crop_data['亩产量/斤'], errors='coerce')
merged_crop_data['销售单价/(元/斤)'] = pd.to_numeric(
    merged_crop_data['销售单价/(元/斤)'].str.extract('(\d+\.?\d*)')[0], errors='coerce')
merged_crop_data['种植成本/(元/亩)'] = pd.to_numeric(merged_crop_data['种植成本/(元/亩)'], errors='coerce')
merged_land_data['地块面积/亩'] = pd.to_numeric(merged_land_data['地块面积/亩'], errors='coerce')

# 处理缺失值
merged_crop_data = merged_crop_data.dropna(subset=['作物名称', '种植面积/亩', '亩产量/斤', '销售单价/(元/斤)', '种植成本/(元/亩)'])
merged_land_data = merged_land_data.dropna(subset=['地块名称', '地块面积/亩'])

# 定义参数
years = range(2024, 2031)  # 从2024年到2030年
crops = merged_crop_data['作物名称'].unique()  # 作物列表
lands = merged_land_data['地块名称'].unique()  # 地块列表


# 初始化线性规划问题
def create_model(case):
    model = LpProblem(name=f"Crop_Optimization_Case{case}", sense=LpMaximize)

    # 定义决策变量 X[i, j, t]: i 作物，j 地块，t 年的种植面积
    X = LpVariable.dicts("X", ((i, j, t) for i in crops for j in lands for t in years), lowBound=0, cat='Continuous')

    # 定义超出部分的变量 Excess[i, j, t]: 超出预期销售量的部分
    Excess = LpVariable.dicts("Excess", ((i, j, t) for i in crops for j in lands for t in years), lowBound=0, cat='Continuous')

    # 计算收益和成本
    crop_yields = merged_crop_data.set_index('作物名称')['亩产量/斤'].to_dict()
    crop_prices = merged_crop_data.set_index('作物名称')['销售单价/(元/斤)'].to_dict()
    crop_costs = merged_crop_data.set_index('作物名称')['种植成本/(元/亩)'].to_dict()
    land_areas = merged_land_data.set_index('地块名称')['地块面积/亩'].to_dict()
    expected_sales = merged_crop_data.set_index('作物名称')['种植面积/亩'].to_dict()

    # 修改目标函数，增加种植面积分配的动力
    if case == 1:
        # 情况1：滞销浪费，鼓励种植面积分配
        model += lpSum(((X[i, j, t] * crop_yields.get(i, 0) - Excess[
            i, j, t]) * crop_prices.get(i, 0)
                        - X[i, j, t] * crop_costs.get(i, 0)) + 0.1 * X[i, j, t]
                       for i in crops for j in lands for t in years)
    elif case == 2:
        # 情况2：降价出售，鼓励种植面积分配
        model += lpSum(((X[i, j, t] * crop_yields.get(i, 0) - Excess[
            i, j, t]) * crop_prices.get(i, 0)
                        + Excess[i, j, t] * crop_prices.get(i, 0) * 0.5
                        - X[i, j, t] * crop_costs.get(i, 0)) + 0.1 * X[i, j, t]
                       for i in crops for j in lands for t in years)

    # 添加约束条件
    for i in crops:
        for j in lands:
            for t in years:
                if crop_yields.get(i, 0) > 0:
                    model += Excess[i, j, t] >= X[i, j, t] * crop_yields.get(i, 0) - expected_sales.get(i, 0), f"excess_limit_{i}_{j}_{t}"

    # 约束1：种植面积不能超过地块面积
    for j in lands:
        for t in years:
            model += lpSum(X[i, j, t] for i in crops) <= land_areas.get(j, 0), f"land_area_{j}_{t}"

    # 约束2：同一块地不能连续种植相同作物
    for j in lands:
        for i in crops:
            for t in years[1:]:
                model += X[i, j, t] <= 0.9 * X[i, j, t - 1], f"limited_same_crop_{i}_{j}_{t}"

    # 约束3：每个地块三年内至少种植一次豆类作物
    legume_crops = [crop for crop in crops if '豆' in crop]
    for j in lands:
        for t in range(2024, 2031, 3):
            if t + 2 <= 2030:
                model += lpSum(X[i, j, t + k] for i in legume_crops for k in range(3)) >= 0.5, f"legume_{j}_{t}"

    return model, X

# 创建两个模型，分别代表两种情况
model1, X1 = create_model(1)  # 滞销浪费
model2, X2 = create_model(2)  # 降价出售

# 求解模型
model1.solve()
model2.solve()

# 打印求解状态
print(f"Case 1 Status: {model1.status}, {LpStatus[model1.status]}")
print(f"Case 2 Status: {model2.status}, {LpStatus[model2.status]}")

# 读取现有的 result1_2.xlsx 和 result1_1.xlsx
result1_2 = pd.read_excel('./result1_2.xlsx', sheet_name=None)
result1_1 = pd.read_excel('./result1_1.xlsx', sheet_name=None)

# 更新结果的函数
def update_result(result_df, X, years, crops, lands):
    for year in years:
        sheet_name = str(year)
        if sheet_name in result_df:
            for j in lands:
                for i in crops:
                    value = X[i, j, year].varValue
                    if value is not None:
                        if i in result_df[sheet_name].columns and j in result_df[sheet_name]['地块名'].values:
                            # 更新表格中的种植面积，确保种植面积为合理范围
                            value = max(0, round(value, 2))  # 将负值设为0，且保留两位小数
                            result_df[sheet_name].loc[result_df[sheet_name]['地块名'] == j, i] = value
                        else:
                            print(f"列名或地块名不匹配：作物 {i} 或地块 {j} 未找到")
                    else:
                        # 如果没有值，则默认填充为0
                        if i in result_df[sheet_name].columns and j in result_df[sheet_name]['地块名'].values:
                            result_df[sheet_name].loc[result_df[sheet_name]['地块名'] == j, i] = 0
    return result_df

# 调用更新函数
result1_1 = update_result(result1_1, X1, years, crops, lands)  # 滞销浪费的结果
result1_2 = update_result(result1_2, X2, years, crops, lands)  # 降价出售的结果

# 使用 ExcelWriter 保存到新的文件中
with pd.ExcelWriter('./result1_1.xlsx') as writer:
    for sheet_name, df in result1_1.items():
        df.to_excel(writer, sheet_name=sheet_name, index=False)

with pd.ExcelWriter('./result1_2.xlsx') as writer:
    for sheet_name, df in result1_2.items():
        df.to_excel(writer, sheet_name=sheet_name, index=False)



