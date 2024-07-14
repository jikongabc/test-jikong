import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import SGDRegressor
from sklearn.metrics import mean_squared_error
from scipy.optimize import dual_annealing
import numpy as np
import matplotlib.pyplot as plt

from pylab import mpl
mpl.rcParams["font.sans-serif"] = ["SimHei"] # 设置显示中文字体 宋体
mpl.rcParams["axes.unicode_minus"] = False #字体更改后，会导致坐标轴中的部分字符无法正常显示，此时需要设置正常显示负号

# Load the data
file_path = 'C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/222.xlsx'  # Update the path to your file
data = pd.read_excel(file_path)

# Separate features and target variable
X = data.drop('y', axis=1)
y = data['y']

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Normalize the feature data
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Gradient Descent Optimization
sgd_regressor = SGDRegressor(max_iter=1000, tol=1e-3, random_state=42)
sgd_regressor.fit(X_train_scaled, y_train)
y_pred_sgd = sgd_regressor.predict(X_test_scaled)
mse_sgd = mean_squared_error(y_test, y_pred_sgd)

# Simulated Annealing Optimization
def objective_function(params):
    intercept = params[0]
    coef = params[1:]
    y_pred = np.dot(X_train_scaled, coef) + intercept
    mse = mean_squared_error(y_train, y_pred)
    return mse

bounds = [(-10, 10)] * (X_train_scaled.shape[1] + 1)
result = dual_annealing(objective_function, bounds, maxiter=1000)
best_params = result.x
intercept_sa = best_params[0]
coef_sa = best_params[1:]
y_pred_sa = np.dot(X_test_scaled, coef_sa) + intercept_sa
mse_sa = mean_squared_error(y_test, y_pred_sa)

# Plotting the results
fig, ax = plt.subplots(figsize=(10, 6))
ax.scatter(y_test, y_pred_sgd, color='blue', label='梯度下降预测')
ax.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'k--', lw=2)
ax.scatter(y_test, y_pred_sa, color='red', label='模拟退火预测', alpha=0.6)
ax.set_xlabel('实际值')
ax.set_ylabel('期望值')
ax.set_title('梯度下降和模拟退火预测的比较')
ax.legend()
plt.show()

# Print Mean Squared Errors
print(f'Mean Squared Error (Gradient Descent): {mse_sgd}')
print(f'Mean Squared Error (Simulated Annealing): {mse_sa}')
