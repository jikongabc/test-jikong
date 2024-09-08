% 读取Excel文件并保留原始列名
filename = '附件1-1.xlsx'; % 将此文件名替换为你的实际文件名
data = readtable(filename, 'VariableNamingRule', 'preserve');

% 使用检查过的列名提取数据
plot_names = data.('地块名称');  % 确认列名
land_area = data.('地块面积');    % 确认列名
%t1
% 创建图窗
figure;

% 可视化：条形图展示各地块的占地面积
bar(land_area);
set(gca, 'XTickLabel', plot_names, 'XTickLabelRotation', 45); % 设置X轴标签
xlabel('地块名称');
ylabel('占地面积 (亩)');
title('各地块的占地面积分布');

% 调整图窗大小和位置
set(gca, 'Position', [0.1, 0.3, 0.85, 0.6]); 
set(gcf, 'Position', [100, 100, 1000, 600]);
%t1