% 读取Excel文件并保留原始列名
filename = '附件2-2清洗后数据.xlsx'; % 将文件名替换为你实际的文件名
data = readtable(filename, 'VariableNamingRule', 'preserve');

% 提取数据
crop_names = data.('作物名称');              % 使用括号访问作物名称
yield_per_acre = data.('亩产量/斤');         % 使用括号访问亩产量
cost_per_acre = data.('种植成本/(元/亩)');  % 使用括号访问种植成本
price_per_kg = data.('销售单价/(元/斤)');   % 使用括号访问销售单价
%
% 创建一个新的图窗
figure;

% 绘制亩产量柱状图
subplot(3,1,1); % 子图 1
bar(yield_per_acre);
set(gca, 'XTickLabel', crop_names, 'XTickLabelRotation', 45); % 旋转标签以便于显示
ylabel('亩产量（斤）');
title('不同作物的亩产量');

% 绘制种植成本柱状图
subplot(3,1,2); % 子图 2
bar(cost_per_acre);
set(gca, 'XTickLabel', crop_names, 'XTickLabelRotation', 45); % 旋转标签以便于显示
ylabel('种植成本（元/亩）');
title('不同作物的种植成本');

% 绘制销售单价柱状图
subplot(3,1,3); % 子图 3
bar(price_per_kg);
set(gca, 'XTickLabel', crop_names, 'XTickLabelRotation', 45); % 旋转标签以便于显示
ylabel('销售单价（元/斤）');
title('不同作物的销售单价');%t1

% 调整子图之间的间距
set(gcf, 'Position', [100, 100, 800, 600]); % 调整图窗大小
subplot(3,1,1);  % 子图 1 调整边距
set(gca, 'Position', [0.1, 0.7, 0.85, 0.2]); % [left, bottom, width, height]

subplot(3,1,2);  % 子图 2 调整边距
set(gca, 'Position', [0.1, 0.4, 0.85, 0.2]); 

subplot(3,1,3);  % 子图 3 调整边距
set(gca, 'Position', [0.1, 0.1, 0.85, 0.2]); 

% 添加全局标题
sgtitle('作物亩产量、种植成本和销售单价比较');


%t1