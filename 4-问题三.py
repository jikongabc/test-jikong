import pandas as pd
import numpy as np
import random
import re  # 导入正则表达式模块

# 定义豆类作物集合
legume_crops = ['黄豆', '豇豆', '芸豆', '红豆', '黑豆', '绿豆', '爬豆', '刀豆']

# 定义其他作物类型
grain_crops = ['小麦', '玉米']  # 粮食类作物
vegetable_crops = ['白菜', '生菜', '菠菜', '番茄']  # 蔬菜类作物（示例）
fungi_crops = ['蘑菇', '羊肚菌']  # 食用菌类作物（示例）

#
# 固定公式计算：使用种植成本计算销售单价和亩产量
def adjust_parameters_fixed(crop_name, base_cost):
    # 销售单价和亩产量的固定线性公式
    price = 2.5000 + 0.0032 * base_cost  # 销售单价公式
    yield_per_mu = 300.0000 + 0.0456 * base_cost  # 亩产量公式

    # 种植成本保持不变
    cost = base_cost

    return yield_per_mu, cost, price


# 修改的 find_best_crop 函数：包含固定公式
def find_best_crop(season_crops, crop_data, plot_area, expected_sales_factor, min_plot_area):
    best_revenue = -float('inf')
    best_crop_idx = 0

    # 遍历每个作物，计算收益
    for crop_idx in range(len(season_crops)):
        crop_name = season_crops.iloc[crop_idx]['作物名称']
        crop_data_filtered = crop_data[crop_data['作物名称'] == crop_name]

        if not crop_data_filtered.empty:
            # 获取基础数据（种植成本）
            base_cost = crop_data_filtered.iloc[0]['种植成本/(元/亩)']

            # 使用固定公式计算销售单价和亩产量
            yield_per_mu, cost, price = adjust_parameters_fixed(crop_name, base_cost)

            # 计算总产量和预期销售量
            total_production = yield_per_mu * plot_area
            expected_sales = expected_sales_factor * total_production

            # 计算超出部分的产量
            surplus_production = max(0, total_production - expected_sales)
            regular_sales = min(total_production, expected_sales)

            # 收益 = 正常销售的部分 + 降价后的超出部分
            revenue = regular_sales * price + surplus_production * (price * 0.5) - cost * plot_area

            # 确保逻辑条件是标量
            if revenue > best_revenue and plot_area >= min_plot_area:
                best_revenue = revenue
                best_crop_idx = crop_data.index[crop_data['作物名称'] == crop_name][0]

    return best_crop_idx, best_revenue


# 导入数据
land_filename = '附件1-1.xlsx'
land_data = pd.read_excel(land_filename)

land_types = ['普通大棚', '智慧大棚', '平旱地', '梯田', '山坡地', '水浇地']
plot_info = pd.DataFrame()

# 整理地块信息#
for land_type in land_types:
    names = land_data[land_data['地块类型'] == land_type]['地块名称']
    areas = land_data[land_data['地块类型'] == land_type]['地块面积']
    temp_df = pd.DataFrame({'种植地块': names, '地块类型': land_type, '地块面积': areas})
    plot_info = pd.concat([plot_info, temp_df])

# 导入2023年种植数据
planting_filename = '附件2-1导入.xlsx'
planting_data_2023 = pd.read_excel(planting_filename)

# 添加地块信息
planting_data_2023 = pd.merge(planting_data_2023, plot_info, on='种植地块', how='left')

# 导入作物数据
crop_filename = '附件2-2清洗后数据.xlsx'
crop_data = pd.read_excel(crop_filename)

# 导入和处理作物-土地适用数据
filename = '附件1-2.xlsx'
crop_land_data = pd.read_excel(filename)

# 分解作物适用地块和季节
land_types_all, seasons_all, crop_ids_all, crop_names_all, crop_types_all = [], [], [], [], []
for i in range(len(crop_land_data)):#
    suitable_lands = str(crop_land_data.iloc[i]['种植耕地']).replace('↵', '').strip()
    if suitable_lands:
        tokens = re.findall(r'(\S+)\s+(\S+)', suitable_lands)
        for land_type, season in tokens:
            seasons = season.split()
            for season_part in seasons:
                crop_ids_all.append(crop_land_data.iloc[i]['作物编号'])
                crop_names_all.append(crop_land_data.iloc[i]['作物名称'])
                crop_types_all.append(crop_land_data.iloc[i]['作物类型'])
                land_types_all.append(land_type)
                seasons_all.append(season_part)

result_table = pd.DataFrame({
    '作物编号': crop_ids_all,
    '作物名称': crop_names_all,
    '作物类型': crop_types_all,
    '地块类型': land_types_all,
    '季节': seasons_all
})

# 导出结果#
result_table.to_excel('分解后的作物地块和季节信息.xlsx', index=False)

# 主代码块 - 根据每年的参数变化计算最优种植方案
years = list(range(2024, 2031))
num_years = len(years)
plot_names = plot_info['种植地块'].values
plot_areas = plot_info['地块面积'].values
num_plots = len(plot_names)
num_crops = len(crop_data)

expected_sales_factor = 0.8
min_plot_area = 0.1
last_crop_planted = np.empty((num_plots, num_years), dtype=object)
last_legume_year = np.zeros(num_plots)

yearly_plans = []

for year_idx in range(num_years):
    # 调试信息：打印当前年份
    print(f"正在处理年份：{years[year_idx]}")

    # 创建每年种植方案
    year_plan_first_season = np.zeros((num_plots, num_crops))
    year_plan_second_season = np.zeros((num_plots, num_crops))

    # 遍历每个地块
    for plot_idx in range(num_plots):
        plot_name = plot_names[plot_idx]
        plot_area = plot_areas[plot_idx]
        applicable_crops = result_table[result_table['地块类型'] == plot_info.iloc[plot_idx]['地块类型']]

        # 避免重茬种植
        if year_idx > 0:
            last_crop = last_crop_planted[plot_idx, year_idx - 1]
            applicable_crops = applicable_crops[applicable_crops['作物名称'] != last_crop]

        # 检查豆类轮作需求
        if (year_idx - last_legume_year[plot_idx]) >= 3:
            legume_crops_applicable = applicable_crops[applicable_crops['作物名称'].isin(legume_crops)]
            if not legume_crops_applicable.empty:
                applicable_crops = legume_crops_applicable



                # 第一季种植
        season_1_crops = applicable_crops[applicable_crops['季节'] == '第一季']
        total_planted_area_first_season = 0
        if not season_1_crops.empty:
            for crop_idx in range(len(season_1_crops)):
                best_crop_idx, best_revenue = find_best_crop(season_1_crops.iloc[[crop_idx]], crop_data, plot_area,
                                                             expected_sales_factor, min_plot_area)
                if best_crop_idx > 0 and total_planted_area_first_season < plot_area:
                    planting_area = min(plot_area - total_planted_area_first_season, plot_area)
                    year_plan_first_season[plot_idx, best_crop_idx] = planting_area
                    total_planted_area_first_season += planting_area
                    last_crop_planted[plot_idx, year_idx] = crop_data.iloc[best_crop_idx]['作物名称']

                    if crop_data.iloc[best_crop_idx]['作物名称'] in legume_crops:
                        last_legume_year[plot_idx] = year_idx

        # 第二季种植
        season_2_crops = applicable_crops[applicable_crops['季节'] == '第二季']
        total_planted_area_second_season = 0
        if not season_2_crops.empty:
            for crop_idx in range(len(season_2_crops)):
                best_crop_idx, best_revenue = find_best_crop(season_2_crops.iloc[[crop_idx]], crop_data, plot_area,
                                                             expected_sales_factor, min_plot_area)
                if best_crop_idx > 0 and total_planted_area_second_season < plot_area:
                    planting_area =min(plot_area - total_planted_area_second_season, plot_area)
                    year_plan_second_season[plot_idx, best_crop_idx] = planting_area
                    total_planted_area_second_season += planting_area
                    last_crop_planted[plot_idx, year_idx] = crop_data.iloc[best_crop_idx]['作物名称']

                    if crop_data.iloc[best_crop_idx]['作物名称'] in legume_crops:
                        last_legume_year[plot_idx] = year_idx

    # 添加当前年份的种植方案到列表
    yearly_plans.append({
        'year': years[year_idx],
        'first_season': year_plan_first_season,
        'second_season': year_plan_second_season
    })
    print(f"已完成年份：{years[year_idx]} 的种植方案")

# 调试信息：打印整个 yearly_plans 列表长度
print(f"yearly_plans 列表长度：{len(yearly_plans)}")

# 导出种植方案
for year_idx in range(num_years):
    year_plan = yearly_plans[year_idx]
    first_season_df = pd.DataFrame(year_plan['first_season'], columns=crop_data['作物名称'], index=plot_names)
    second_season_df = pd.DataFrame(year_plan['second_season'], columns=crop_data['作物名称'], index=plot_names)

    # 生成文件名
    first_season_filename = f'最优种植方案_第{years[year_idx]}年_第一季.xlsx'
    second_season_filename = f'最优种植方案_第{years[year_idx]}年_第二季.xlsx'

    # 将第一季和第二季的种植方案导出为 Excel 文件
    first_season_df.to_excel(first_season_filename, index=True)
    print(f"已导出：{first_season_filename}")
    second_season_df.to_excel(second_season_filename, index=True)
    print(f"已导出：{second_season_filename}")

print("所有年度的种植方案已成功导出。")

