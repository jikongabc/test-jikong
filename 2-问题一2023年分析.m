%% 导入和处理土地数据
% 文件路径
land_filename = '附件1-1.xlsx';

% 导入 Excel 数据
land_data = readtable(land_filename, 'Sheet', 1, 'ReadVariableNames', true, 'VariableNamingRule', 'preserve');

% 按照地块类型提取名称和面积
land_types = {'普通大棚', '智慧大棚', '平旱地', '梯田', '山坡地', '水浇地'};

% 初始化地块信息
plot_names = [];
plot_areas = [];
plot_types = [];

% 遍历所有地块类型，提取相应的地块名称和面积
for i = 1:length(land_types)
    type = land_types{i};
    names = land_data.('地块名称')(strcmp(land_data.('地块类型'), type));
    areas = land_data.('地块面积')(strcmp(land_data.('地块类型'), type));
    
    plot_names = [plot_names; names];
    plot_areas = [plot_areas; areas];
    plot_types = [plot_types; repmat({type}, length(names), 1)];
end

% 创建包含地块信息的表格
plot_info = table(plot_names, plot_types, plot_areas, 'VariableNames', {'种植地块', '地块类型', '地块面积'});

%% 导入2023年种植数据
planting_filename = '附件2-1导入.xlsx';
planting_data_2023 = readtable(planting_filename, 'Sheet', 1, 'ReadVariableNames', true, 'VariableNamingRule', 'preserve');

% 添加地块信息（地块类型、地块面积）
planting_data_2023 = join(planting_data_2023, plot_info, 'Keys', '种植地块');
disp('2023年种植数据（前10行）：');
disp(planting_data_2023(1:10, :));  % 检查前几行数据

%% 导入作物数据
crop_filename = '附件2-2清洗后数据.xlsx';
crop_data = readtable(crop_filename, 'Sheet', 1, 'ReadVariableNames', true, 'VariableNamingRule', 'preserve');

% 提取相关数据列%t1
crop_names = crop_data.('作物名称');                  % 作物名称
plot_types = crop_data.('地块类型');                  % 地块类型
planting_seasons = crop_data.('种植季次');            % 种植季次
yield_per_mu = crop_data.('亩产量/斤');               % 亩产量/斤
planting_costs = crop_data.('种植成本/(元/亩)');      % 种植成本/(元/亩)
sale_prices = crop_data.('销售单价/(元/斤)');         % 销售单价/(元/斤)

%% 合并数据并仅保留2023年种植数据中的条目
% 使用 innerjoin 进行合并，只保留两个表格中都存在的条目
merged_data = innerjoin(planting_data_2023, crop_data, 'Keys', {'作物名称', '种植季次', '地块类型'});

% 检查合并后的数据
disp('合并后的数据（前10行）：');
disp(merged_data(1:10, :));



%% 计算总产量和收益
% 提取合并后的亩产量、种植面积和销售价格
yield_per_mu = merged_data.('亩产量/斤');
planting_areas = merged_data.('种植面积/亩');
sale_prices = merged_data.('销售单价/(元/斤)');

% 计算每种作物的总产量
total_productions = yield_per_mu .* planting_areas;

% 计算预期销售量为总产量的80%
expected_sales = 0.8 * total_productions;

% 初始化收益数组
total_revenue_case1 = zeros(size(total_productions));
total_revenue_case2 = zeros(size(total_productions));

% 计算两种情况下的收益
for i = 1:length(total_productions)
    production = total_productions(i);
    expected_sale = expected_sales(i);%t1
    price = sale_prices(i);
    
    % 情况1: 滞销部分浪费
    if production <= expected_sale
        total_revenue_case1(i) = production * price;
    else
        total_revenue_case1(i) = expected_sale * price;  % 超出部分浪费
    end
    
    % 情况2: 超出部分按50%降价出售
    if production <= expected_sale
        total_revenue_case2(i) = production * price;
    else
        excess_production = production - expected_sale;
        total_revenue_case2(i) = expected_sale * price + excess_production * price * 0.5;
    end
end

% 输出收益结果
disp('情况1: 滞销部分浪费的总收益:');
disp(total_revenue_case1);%t1

disp('情况2: 超过部分降价出售的总收益:');
disp(total_revenue_case2);
% 获取作物名称和对应的两种收益
crop_names = merged_data.('作物名称');  % 提取作物名称
total_revenue_case1 = total_revenue_case1(:);  % 转换为列向量
total_revenue_case2 = total_revenue_case2(:);  % 转换为列向量

% 绘制柱状图进行对比
figure;
bar_width = 0.4;  % 设置柱子的宽度

% 绘制两种收益的柱状图
b1 = bar(1:length(crop_names), total_revenue_case1, bar_width, 'FaceColor', [0.3, 0.6, 0.8]);  % 情况1, 蓝色
hold on;
b2 = bar(1:length(crop_names) + bar_width, total_revenue_case2, bar_width, 'FaceColor', [0.9, 0.5, 0.5]);  % 情况2, 红色

% 设置作物名称为x轴标签
xticks(1:length(crop_names) + bar_width/2);  % 设置x轴的刻度位置
xticklabels(crop_names);  % 将作物名称作为x轴标签
xtickangle(45);  % 旋转x轴标签以避免重叠

% 图例%t1
legend([b1, b2], {'情况1: 滞销浪费', '情况2: 超出部分降价'}, 'Location', 'NorthWest');

% 添加标题和轴标签
title('2023年两种情况下的收益对比', 'FontSize', 14, 'FontWeight', 'bold');
xlabel('作物名称', 'FontSize', 12);
ylabel('总收益（元）', 'FontSize', 12);

% 设置网格
grid on;
set(gca, 'GridAlpha', 0.3);  % 设置网格线的透明度

% 美化图表
set(gca, 'FontSize', 12);  % 设置刻度字体大小
set(gca, 'box', 'off');  % 移除边框线
hold off;

% 自动调整图表尺寸以避免重叠
set(gcf, 'Position', [100, 100, 1200, 600]);  % 设置图表大小


