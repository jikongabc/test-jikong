import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from deap import base, creator, tools, algorithms
import random

# 设置随机种子
SEED = 42
np.random.seed(SEED)
random.seed(SEED)

# Load the data from the uploaded Excel file
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx'
data = pd.read_excel(file_path)

# Convert columns to numeric types, if necessary
data = data.iloc[1:]
data.columns = ['带钢厚度', '带钢宽度', '碳含量', '硅含量', '带钢速度', '加热炉温度', '均热炉温度', '缓冷炉温度', '过时效炉温度', '快冷炉温度', '淬火炉温度', '平整机张力', '硬度']
data = data.apply(pd.to_numeric)

# 选择相关性较高的特征
features = data[['碳含量', '淬火炉温度', '均热炉温度', '快冷炉温度','加热炉温度','过时效炉温度']]
target = data['硬度']

# 分割数据为训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.3, random_state=SEED)

# 建立随机森林回归模型
rf_model = RandomForestRegressor(n_estimators=100, random_state=SEED)
rf_model.fit(X_train, y_train)

# 定义目标函数
def objective_function(params):
    params_df = pd.DataFrame([params], columns=features.columns)
    predicted_hardness = rf_model.predict(params_df)
    return abs(predicted_hardness - target_hardness),

# 遗传算法设置
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
creator.create("Individual", list, fitness=creator.FitnessMin)

toolbox = base.Toolbox()
toolbox.register("attr_float", np.random.uniform, 0, 1)
toolbox.register("individual", tools.initRepeat, creator.Individual, toolbox.attr_float, n=len(features.columns))
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

toolbox.register("mate", tools.cxBlend, alpha=0.5)
toolbox.register("mutate", tools.mutGaussian, mu=0, sigma=0.2, indpb=0.2)
toolbox.register("select", tools.selTournament, tournsize=3)
toolbox.register("evaluate", objective_function)

# 参数边界
param_bounds = {
    '碳含量': (features['碳含量'].min(), features['碳含量'].max()),
    '淬火炉温度': (features['淬火炉温度'].min(), features['淬火炉温度'].max()),
    '均热炉温度': (features['均热炉温度'].min(), features['均热炉温度'].max()),
    '快冷炉温度': (features['快冷炉温度'].min(), features['快冷炉温度'].max()),
    '加热炉温度': (features['加热炉温度'].min(), features['加热炉温度'].max()),
    '过时效炉温度': (features['过时效炉温度'].min(), features['过时效炉温度'].max())
}

# 初始化个体
def initialize_individual(icls, bounds):
    individual = icls()
    for key in bounds:
        individual.append(np.random.uniform(bounds[key][0], bounds[key][1]))
    return individual

toolbox.register("individual", initialize_individual, creator.Individual, param_bounds)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

# 运行遗传算法
population = toolbox.population(n=50)
ngen = 100
cxpb = 0.5
mutpb = 0.2

target_hardness = 600

result_pop, logbook = algorithms.eaSimple(population, toolbox, cxpb=cxpb, mutpb=mutpb, ngen=ngen, verbose=False)

# 获取最佳个体
best_individual = tools.selBest(result_pop, k=1)[0]
optimized_params = best_individual

print("优化后的参数：", optimized_params)
