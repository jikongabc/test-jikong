#include <stdio.h>
double values[1010];      // 用于存储加法和乘法的计算结果
int is_mul[1010];         // 标记是否为乘法项，1表示乘法，0表示加法
double factors[1010][1010]; // 存储每个乘法表达式的因子
int factor_count[1010];   // 存储每个乘法表达式的因子数量
int count = 0;            // 表达式的计数

// 冒泡排序函数，用于排序数组中的数
void bubble_sort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 对所有表达式按结果值排序，同时调整乘法标记和因子数组顺序
void sort_expressions() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (values[j] > values[j + 1]) {
                // 交换值
                double temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;

                // 交换乘法标记
                int temp_flag = is_mul[j];
                is_mul[j] = is_mul[j + 1];
                is_mul[j + 1] = temp_flag;

                // 交换因子数组
                double temp_factors[1010];
                int temp_count = factor_count[j];
                for (int k = 0; k < factor_count[j]; k++) {
                    temp_factors[k] = factors[j][k];
                }

                factor_count[j] = factor_count[j + 1];
                for (int k = 0; k < factor_count[j + 1]; k++) {
                    factors[j][k] = factors[j + 1][k];
                }

                factor_count[j + 1] = temp_count;
                for (int k = 0; k < temp_count; k++) {
                    factors[j + 1][k] = temp_factors[k];
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char c;
    double t;
    int cnt = 0;
    while (1) {
        scanf("%lf%c", &t, &c);
        cnt++;
        if (c == '*') {
            // 当前是乘法表达式
            values[count] = t;
            is_mul[count] = 1;
            factors[count][0] = t;
            int pos = 1;

            // 读取乘法部分的因子
            while (1) {
                scanf("%lf%c", &t, &c);
                cnt++;
                values[count] *= t;
                factors[count][pos++] = t;
                if (c != '*' || cnt >= n) break;
            }

            factor_count[count] = pos; // 设置当前乘法表达式的因子数量

            // 对当前乘法表达式的因子排序
            bubble_sort(factors[count], factor_count[count]);

            count++;
        } else {
            // 当前是加法表达式
            values[count] = t;
            is_mul[count] = 0;
            factor_count[count] = 1; // 单个数值的加法项只有一个因子
            factors[count][0] = t;
            count++;
        }

        if (c != '+' && c != '*' || cnt >= n) break;
    }

    // 对所有表达式排序
    sort_expressions();

    // 输出结果
    for (int i = 0; i < count; i++) {
        if (i > 0) printf("+");

        if (is_mul[i]) {
            // 输出乘法表达式
            for (int j = 0; j < factor_count[i]; j++) {
                if (j > 0) printf("*");
                printf("%.2lf", factors[i][j]);
            }
        } else {
            // 输出单个加法项
            printf("%.2lf", values[i]);
        }
    }

    printf("\n");

    return 0;
}
