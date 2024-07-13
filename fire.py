import pandas as pd
import numpy as np
from scipy.optimize import minimize, dual_annealing
from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import StandardScaler

# 读取数据
data = pd.read_excel('C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx')  # 确保路径和文件名正确

# 转换数据类型
for column in data.columns:
    data[column] = pd.to_numeric(data[column], errors='coerce')

# 处理缺失值：删除包含缺失值的行
data_cleaned = data.dropna()

# 特征和标签
X = data_cleaned.drop(columns='y')
y = data_cleaned['y']

# 标准化特征
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 训练随机森林模型
model_rf = RandomForestRegressor(n_estimators=100, random_state=42)
model_rf.fit(X, y)

# 初步优化参数（假设是遗传算法得到的）
initial_params = np.array([8091.93, 219.62, 371.26, 13.24, 696.96, 733.97, 641.73, 638.05, 385.67, 67.93, 44.46, 2700.63])

# 定义目标函数
def objective_function(params):
    input_data = pd.DataFrame([params], columns=X.columns)
    y_pred = model_rf.predict(input_data)
    target_hardness = 600  # 假设目标硬度为600
    return (y_pred[0] - target_hardness)**2

# 定义参数范围（假设为每个参数设定合理范围）
bounds = [(8000, 9000), (180, 250), (200, 500), (5, 20), (500, 700),
          (700, 800), (600, 750), (600, 750), (300, 400), (40, 80),
          (40, 50), (2000, 3000)]

# 使用模拟退火进行微调
result_sa = dual_annealing(objective_function, bounds=bounds, x0=initial_params)
optimal_params_sa = result_sa.x
sa_objective_value = objective_function(optimal_params_sa)

# 使用梯度下降进行微调
result_gd = minimize(objective_function, initial_params, method='BFGS')
optimal_params_gd = result_gd.x
gd_objective_value = objective_function(optimal_params_gd)

# 输出结果
print("Optimal parameters using Simulated Annealing:")
print(optimal_params_sa)
print("Objective function value (Simulated Annealing):")
print(sa_objective_value)

print("\nOptimal parameters using Gradient Descent:")
print(optimal_params_gd)
print("Objective function value (Gradient Descent):")
print(gd_objective_value)

# 比较两种方法的效果
if sa_objective_value < gd_objective_value:
    print("\nSimulated Annealing provides a better solution.")
else:
    print("\nGradient Descent provides a better solution.")
