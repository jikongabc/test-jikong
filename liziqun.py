import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from pyswarm import pso
import random

# 设置随机种子
SEED = 42
np.random.seed(SEED)
random.seed(SEED)

# 读取数据
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/222.xlsx'
data = pd.read_excel(file_path)

# 转换列为数值类型
data = data.iloc[1:]
data.columns = ['带钢厚度', '带钢宽度', '碳含量', '硅含量', '带钢速度', '加热炉温度', '均热炉温度', '缓冷炉温度', '过时效炉温度', '快冷炉温度', '淬火炉温度', '平整机张力', '硬度']
data = data.apply(pd.to_numeric)

# 选择特征和目标变量
features = data[['带钢厚度', '带钢宽度', '碳含量', '硅含量', '带钢速度', '加热炉温度', '均热炉温度', '缓冷炉温度', '过时效炉温度', '快冷炉温度', '淬火炉温度', '平整机张力']]
target = data['硬度']

# 分割数据集
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.3, random_state=SEED)

# 建立随机森林模型
rf_model = RandomForestRegressor(n_estimators=100, random_state=SEED)
rf_model.fit(X_train, y_train)

# 定义目标函数
def objective_function(params):
    params_df = pd.DataFrame([params], columns=features.columns)
    predicted_hardness = rf_model.predict(params_df)
    return abs(predicted_hardness - target_hardness)

# 参数边界
param_bounds = [
    (features['带钢厚度'].min(), features['带钢厚度'].max()),
    (features['带钢宽度'].min(), features['带钢宽度'].max()),
    (features['碳含量'].min(), features['碳含量'].max()),
    (features['硅含量'].min(), features['硅含量'].max()),
    (features['带钢速度'].min(), features['带钢速度'].max()),
    (features['加热炉温度'].min(), features['加热炉温度'].max()),
    (features['均热炉温度'].min(), features['均热炉温度'].max()),
    (features['缓冷炉温度'].min(), features['缓冷炉温度'].max()),
    (features['过时效炉温度'].min(), features['过时效炉温度'].max()),
    (features['快冷炉温度'].min(), features['快冷炉温度'].max()),
    (features['淬火炉温度'].min(), features['淬火炉温度'].max()),
    (features['平整机张力'].min(), features['平整机张力'].max())
]

# 设置目标硬度
target_hardness = 600

# 使用粒子群算法进行优化
lb = [bound[0] for bound in param_bounds]
ub = [bound[1] for bound in param_bounds]
optimized_params, _ = pso(objective_function, lb, ub, swarmsize=50, maxiter=100)

# 格式化输出优化后的参数
optimized_params_formatted = [f'{param:.4f}' for param in optimized_params]

print("优化后的参数：", optimized_params_formatted)
