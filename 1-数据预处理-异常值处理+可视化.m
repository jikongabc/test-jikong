% 读取Excel文件并保留原始列名
filename = '附件2-2清洗后数据.xlsx'; % 将文件名替换为你实际的文件名
data = readtable(filename, 'VariableNamingRule', 'preserve');

% 提取数据并删除缺失值
yield_per_acre = rmmissing(data.('亩产量/斤'));         % 使用括号访问亩产量并删除缺失值
cost_per_acre = rmmissing(data.('种植成本/(元/亩)'));  % 使用括号访问种植成本并删除缺失值
price_per_kg = rmmissing(data.('销售单价/(元/斤)'));   % 使用括号访问销售单价并删除缺失值

% 正态性检验 (使用kstest，删除缺失值后进行检验)
is_normal_yield = kstest((yield_per_acre - mean(yield_per_acre)) / std(yield_per_acre));
is_normal_cost = kstest((cost_per_acre - mean(cost_per_acre)) / std(cost_per_acre));
is_normal_price = kstest((price_per_kg - mean(price_per_kg)) / std(price_per_kg));

% 可视化：创建一个新的图窗
figure;

% 绘制亩产量异常值处理图
subplot(3,1,1);
if is_normal_yield == 0
    % 正态分布，使用3σ原则
    mu_yield = mean(yield_per_acre);
    sigma_yield = std(yield_per_acre);
    outliers_yield = yield_per_acre(abs(yield_per_acre - mu_yield) > 3 * sigma_yield);%t1
    histogram(yield_per_acre, 'Normalization', 'pdf');
    hold on;
    xline(mu_yield - 3 * sigma_yield, '--r', '3σ下限');
    xline(mu_yield + 3 * sigma_yield, '--r', '3σ上限');
    scatter(find(ismember(yield_per_acre, outliers_yield)), outliers_yield, 'r', 'filled');
    title('亩产量 (正态分布 - 3σ原则)');
else
    % 非正态分布，使用箱型图
    boxplot(yield_per_acre);
    title('亩产量 (非正态分布 - 箱型图)');
end
hold off;

% 绘制种植成本异常值处理图
subplot(3,1,2);
if is_normal_cost == 0
    % 正态分布，使用3σ原则
    mu_cost = mean(cost_per_acre);
    sigma_cost = std(cost_per_acre);
    outliers_cost = cost_per_acre(abs(cost_per_acre - mu_cost) > 3 * sigma_cost);
    histogram(cost_per_acre, 'Normalization', 'pdf');
    hold on;
    xline(mu_cost - 3 * sigma_cost, '--r', '3σ下限');
    xline(mu_cost + 3 * sigma_cost, '--r', '3σ上限');
    scatter(find(ismember(cost_per_acre, outliers_cost)), outliers_cost, 'r', 'filled');
    title('种植成本 (正态分布 - 3σ原则)');
else
    % 非正态分布，使用箱型图
    boxplot(cost_per_acre);
    title('种植成本 (非正态分布 - 箱型图)');
end
hold off;

% 绘制销售单价异常值处理图
subplot(3,1,3);
if is_normal_price == 0%t1
    % 正态分布，使用3σ原则
    mu_price = mean(price_per_kg);
    sigma_price = std(price_per_kg);
    outliers_price = price_per_kg(abs(price_per_kg - mu_price) > 3 * sigma_price);
    histogram(price_per_kg, 'Normalization', 'pdf');
    hold on;
    xline(mu_price - 3 * sigma_price, '--r', '3σ下限');
    xline(mu_price + 3 * sigma_price, '--r', '3σ上限');
    scatter(find(ismember(price_per_kg, outliers_price)), outliers_price, 'r', 'filled');
    title('销售单价 (正态分布 - 3σ原则)');
else
    % 非正态分布，使用箱型图
    boxplot(price_per_kg);
    title('销售单价 (非正态分布 - 箱型图)');
end
hold off;

% 添加全局标题
sgtitle('作物亩产量、种植成本和销售单价的异常值检测');
%t1