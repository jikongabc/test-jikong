

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
%t1
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

% 提取相关数据列
crop_names = crop_data.('作物名称');                  % 作物名称
plot_types = crop_data.('地块类型');                  % 地块类型
planting_seasons = crop_data.('种植季次');            % 种植季次
yield_per_mu = crop_data.('亩产量/斤');               % 亩产量/斤
planting_costs = crop_data.('种植成本/(元/亩)');      % 种植成本/(元/亩)
sale_prices = crop_data.('销售单价/(元/斤)');         % 销售单价/(元/斤)

%% 导入和处理作物-土地适用数据
filename = '附件1-2.xlsx';  % 替换为实际的文件路径

% 导入 Excel 数据
crop_land_data = readtable(filename, 'Sheet', 1, 'ReadVariableNames', true, 'VariableNamingRule', 'preserve');

% 检查导入的数据
disp('导入的作物-土地适用数据:');
disp(crop_land_data(1:30, :));  % 显示前30行数据以检查

% 现在，我们提取作物编号、作物名称、作物类型以及它们适用的地块类型和季节
crop_ids = crop_land_data.('作物编号');      % 作物编号
crop_names = crop_land_data.('作物名称');    % 作物名称
crop_types = crop_land_data.('作物类型');    % 作物类型
crop_suitable_lands = crop_land_data.('种植耕地');  % 适用地块类型及季节

% 初始化存储分解后的信息
land_types_all = {};  % 存储拆解后的地块类型
seasons_all = {};     % 存储拆解后的季节信息
crop_ids_all = [];    % 作物编号
crop_names_all = {};  % 作物名称
crop_types_all = {};  % 作物类型

% 遍历所有作物，处理土地类型和季节
for i = 1:height(crop_land_data)
    suitable_lands = crop_suitable_lands{i};  % 适用地块及季节信息
    
    % 处理换行符和移除多余字符（例如：↵）
    suitable_lands = strrep(suitable_lands, '↵', '');  % 移除特殊字符
    
    % 检查是否为空字符
    if isempty(suitable_lands)
        continue;  % 跳过空值
    end
    
    % 使用正则表达式处理这种地块和季节的结构
    % 匹配 [地块类型 季节] 组合，比如 "水浇地 第一季 普通大棚 第一季 智慧大棚 第一季 第二季"
    tokens = regexp(suitable_lands, '(?<land_type>\S+)\s(?<season>\S+)', 'names');
    
    for j = 1:length(tokens)
        land_type = tokens(j).land_type;  % 地块类型
        season = tokens(j).season;        % 季节
        %t1
        % 如果包含多个季节，继续分割
        seasons = strsplit(season, ' ');
        for k = 1:length(seasons)
            % 添加作物编号、名称、类型到拆解列表中
            crop_ids_all(end+1, 1) = crop_ids(i);
            crop_names_all{end+1, 1} = crop_names{i};
            crop_types_all{end+1, 1} = crop_types{i};
            
            % 存储地块类型和季节
            land_types_all{end+1, 1} = land_type;
            seasons_all{end+1, 1} = strtrim(seasons{k});
        end
    end
end%t1

% 显示分解后的作物信息、地块类型和季节
result_table = table(crop_ids_all, crop_names_all, crop_types_all, land_types_all, seasons_all, ...
                     'VariableNames', {'作物编号', '作物名称', '作物类型', '地块类型', '季节'});

disp('分解后的作物信息、地块类型和季节:');
disp(result_table);
%t1
% 导出结果为 Excel 文件
writetable(result_table, '分解后的作物地块和季节信息.xlsx');

