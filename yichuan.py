from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score
import pandas as pd

# 读取数据
data = pd.read_excel('C:/Users/罗祥/PycharmProjects/pythonProject8/好课优选/附件1.xlsx')

# # 查看数据的基本信息
# data.info()
#
# # 显示前几行数据
# data.head()

# 转换数据类型
for column in data.columns:
    data[column] = pd.to_numeric(data[column], errors='coerce')

# # 查看数据转换后的信息
# data_info_after_conversion = data.info()

# 处理缺失值：这里我们选择删除包含缺失值的行
data_cleaned = data.dropna()

# # 显示清洗后的数据
# data_cleaned_info = data_cleaned.info()
# data_cleaned_head = data_cleaned.head()
#
# data_info_after_conversion, data_cleaned_info, data_cleaned_head

# 特征和标签
X = data_cleaned.drop(columns='y')
y = data_cleaned['y']

# 分割数据集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 选择随机森林模型
model_rf = RandomForestRegressor(n_estimators=100, random_state=42)

# 训练模型
model_rf.fit(X_train, y_train)

# 预测
y_pred_rf = model_rf.predict(X_test)

# 模型评估
mse_rf = mean_squared_error(y_test, y_pred_rf)
r2_rf = r2_score(y_test, y_pred_rf)

# mse_rf, r2_rf
# print(mse_rf)
# print(r2_rf)

from scipy.optimize import differential_evolution

# 定义目标函数
def objective_function(params):
    # 将参数解码回原始尺度
    x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12 = params

    # 构造输入数据
    input_data = pd.DataFrame([params], columns=X.columns)

    # 预测硬度
    y_pred = model_rf.predict(input_data)

    # 目标是硬度的负值（因为遗传算法是求最小化问题）
    return -y_pred[0]


# 定义参数范围（假设为每个参数设定合理范围）
bounds = [(8000, 9000), (180, 250), (200, 500), (5, 20), (500, 700),
          (700, 800), (600, 750), (600, 750), (300, 400), (40, 80),
          (40, 50), (2000, 3000)]

# 执行遗传算法优化
result = differential_evolution(objective_function, bounds, seed=42)

# 输出最优参数
optimal_params = result.x
# optimal_params
print(optimal_params)