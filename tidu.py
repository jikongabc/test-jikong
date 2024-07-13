import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

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
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.3, random_state=42)

# 建立线性回归模型
model = LinearRegression()
model.fit(X_train, y_train)

# 建立随机森林回归模型
rf_model = RandomForestRegressor(n_estimators=100, random_state=42)
rf_model.fit(X_train, y_train)

# 定义目标函数
def objective_function(params, model, target_hardness):
    params_df = pd.DataFrame([params], columns=features.columns)
    predicted_hardness = model.predict(params_df)
    return (predicted_hardness - target_hardness) ** 2

# 设定初始参数（可以使用训练集中的均值作为初始值）
initial_params = X_train.mean().values
target_hardness = 600

# 梯度下降优化函数
def gradient_descent(objective_function, initial_params, model, target_hardness, learning_rate=0.01, max_iter=1000, tol=1e-6):
    params = initial_params
    for _ in range(max_iter):
        grad = np.zeros_like(params)
        for i in range(len(params)):
            params[i] += tol
            loss1 = objective_function(params, model, target_hardness)
            params[i] -= 2 * tol
            loss2 = objective_function(params, model, target_hardness)
            grad[i] = (loss1 - loss2) / (2 * tol)
            params[i] += tol
        params -= learning_rate * grad
        if np.linalg.norm(grad) < tol:
            break
    return params

# 优化工艺参数
optimized_params = gradient_descent(objective_function, initial_params, rf_model, target_hardness)

# 显示优化后的参数
print("优化后的参数：", optimized_params)
