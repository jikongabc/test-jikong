% 读取数据
filename = '附件2-2清洗后数据.xlsx'; % 请替换为实际文件名
data = readtable(filename, 'VariableNamingRule', 'preserve');

% 提取相关数据列
crop_names = data.('作物名称');              % 作物名称
yield_per_acre = data.('亩产量/斤');         % 亩产量/斤
cost_per_acre = data.('种植成本/(元/亩)');  % 种植成本/(元/亩)
price_per_kg = data.('销售单价/(元/斤)');   % 销售单价/(元/斤)

% --- 1. 数据可视化 ---

% 1.1 绘制直方图 (展示数据分布)
figure;
subplot(3,1,1);
histogram(yield_per_acre);
title('亩产量分布');
xlabel('亩产量（斤）');
ylabel('频率');

subplot(3,1,2);
histogram(cost_per_acre);
title('种植成本分布');
xlabel('种植成本（元/亩）');
ylabel('频率');
%t1
subplot(3,1,3);
histogram(price_per_kg);
title('销售单价分布');
xlabel('销售单价（元/斤）');
ylabel('频率');

% 1.2 绘制箱型图 (展示数据的集中趋势和离群点)
figure;
subplot(3,1,1);
boxplot(yield_per_acre);
title('亩产量箱型图');
ylabel('亩产量（斤）');

subplot(3,1,2);
boxplot(cost_per_acre);
title('种植成本箱型图');
ylabel('种植成本（元/亩）');

subplot(3,1,3);
boxplot(price_per_kg);
title('销售单价箱型图');
ylabel('销售单价（元/斤）');

% 1.3 绘制散点图 (展示变量之间的相关性)
figure;
subplot(2,2,1);%t1
scatter(yield_per_acre, cost_per_acre);
title('亩产量 vs 种植成本');
xlabel('亩产量（斤）');
ylabel('种植成本（元/亩）');

subplot(2,2,2);
scatter(yield_per_acre, price_per_kg);
title('亩产量 vs 销售单价');
xlabel('亩产量（斤）');
ylabel('销售单价（元/斤）');

subplot(2,2,3);
scatter(cost_per_acre, price_per_kg);
title('种植成本 vs 销售单价');
xlabel('种植成本（元/亩）');
ylabel('销售单价（元/斤）');

% --- 2. 描述性分析 ---

% 计算均值, 中位数, 标准差, 峰度, 偏度等描述性统计量
mean_yield = mean(yield_per_acre);
median_yield = median(yield_per_acre);
std_yield = std(yield_per_acre);
kurtosis_yield = kurtosis(yield_per_acre);
skewness_yield = skewness(yield_per_acre);

mean_cost = mean(cost_per_acre);%t1
median_cost = median(cost_per_acre);
std_cost = std(cost_per_acre);
kurtosis_cost = kurtosis(cost_per_acre);
skewness_cost = skewness(cost_per_acre);

mean_price = mean(price_per_kg);
median_price = median(price_per_kg);
std_price = std(price_per_kg);
kurtosis_price = kurtosis(price_per_kg);
skewness_price = skewness(price_per_kg);

% 打印描述性统计结果
disp('--- 描述性分析 ---');
fprintf('亩产量: 均值=%.2f, 中位数=%.2f, 标准差=%.2f, 峰度=%.2f, 偏度=%.2f\n', ...
    mean_yield, median_yield, std_yield, kurtosis_yield, skewness_yield);%t1
fprintf('种植成本: 均值=%.2f, 中位数=%.2f, 标准差=%.2f, 峰度=%.2f, 偏度=%.2f\n', ...
    mean_cost, median_cost, std_cost, kurtosis_cost, skewness_cost);
fprintf('销售单价: 均值=%.2f, 中位数=%.2f, 标准差=%.2f, 峰度=%.2f, 偏度=%.2f\n', ...
    mean_price, median_price, std_price, kurtosis_price, skewness_price);

% --- 3. 相关性分析 ---

% 计算相关系数
corr_yield_cost = corr(yield_per_acre, cost_per_acre);
corr_yield_price = corr(yield_per_acre, price_per_kg);
corr_cost_price = corr(cost_per_acre, price_per_kg);

% 打印相关性分析结果
disp('--- 相关性分析 ---');
fprintf('亩产量与种植成本的相关系数: %.2f\n', corr_yield_cost);
fprintf('亩产量与销售单价的相关系数: %.2f\n', corr_yield_price);
fprintf('种植成本与销售单价的相关系数: %.2f\n', corr_cost_price);

