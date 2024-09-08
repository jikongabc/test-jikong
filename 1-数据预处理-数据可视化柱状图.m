% MATLAB Code for Data Visualization

% Data for visualization (Example data from the table you provided)
crops = {'黄豆', '黑豆', '红豆', '绿豆', '爬豆'}; % 作物名称
yield_per_acre = [400, 500, 400, 350, 415]; % 亩产量/斤
cost_per_acre = [400, 400, 350, 350, 350]; % 种植成本/(元/亩)

% For simplicity, we'll average the min and max sales price for each crop
sales_price_min = [2.5, 6.5, 7.5, 6.0, 6.0]; % 销售单价下限/(元/斤)
sales_price_max = [4.0, 8.5, 9.0, 8.0, 7.5]; % 销售单价上限/(元/斤)
average_sales_price = (sales_price_min + sales_price_max) / 2; % 平均销售单价

% Bar plot for yield per acre and cost per acre
figure;
subplot(1, 2, 1);
bar(yield_per_acre);
set(gca, 'xticklabel', crops);
title('Yield per Acre for Different Crops');
ylabel('Yield (斤/亩)');
xlabel('Crops');
grid on;%t1

% Bar plot for cost per acre
subplot(1, 2, 2);
bar(cost_per_acre);
set(gca, 'xticklabel', crops);
title('Cost per Acre for Different Crops');
ylabel('Cost (元/亩)');
xlabel('Crops');
grid on;

% Scatter plot for average sales price and yield per acre
figure;
scatter(average_sales_price, yield_per_acre, 100, 'filled');
title('Average Sales Price vs Yield per Acre');
xlabel('Average Sales Price (元/斤)');
ylabel('Yield per Acre (斤/亩)');
grid on;
text(average_sales_price, yield_per_acre, crops, 'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right');



% 数据输入，作物名称，亩产量，种植成本和销售单价范围
crop_names = {'黄豆', '黑豆', '红豆', '绿豆', '爬豆'};  % 作物名称
yield_per_acre = [400, 500, 400, 350, 415];               % 亩产量
cost_per_acre = [400, 400, 350, 350, 350];                % 种植成本
price_range_min = [2.5, 6.5, 7.5, 6.0, 6.0];             % 销售单价（最小值）
price_range_max = [4.0, 8.5, 9.0, 8.0, 7.5];             % 销售单价（最大值）

% 绘制亩产量柱状图
figure;
bar(yield_per_acre);
set(gca, 'XTickLabel', crop_names);
xlabel('作物名称');
ylabel('亩产量（斤）');
title('不同作物的亩产量');

% 绘制种植成本柱状图
figure;
bar(cost_per_acre);
set(gca, 'XTickLabel', crop_names);
xlabel('作物名称');
ylabel('种植成本（元/亩）');
title('不同作物的种植成本');

% 绘制销售单价范围柱状图
figure;
hold on;
bar(price_range_min, 'FaceColor', [0.2, 0.6, 0.5]);
bar(price_range_max, 'FaceColor', [0.5, 0.2, 0.8]);
set(gca, 'XTickLabel', crop_names);
xlabel('作物名称');%t1
ylabel('销售单价（元/斤）');
title('不同作物的销售单价范围');
legend({'最低单价', '最高单价'});
hold off;
%t1