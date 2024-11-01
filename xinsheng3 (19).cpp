#include <stdio.h>

int a[1010];  

int main() {
    int n, k;
    scanf("%d %d", &n, &k);  // 读取数组长度n和子数组长度k

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // 读取数组元素并存入数组a中
    }

    int s = 0;     // 统计符合“快乐数组”条件的子数组数量
    int cnt = 0;   // 统计子数组总数

    for (int l = 0; l < n - k + 1; l++) {  // 遍历所有可能的长度为k的子数组
        int x = 0;  // 统计该子数组中不对称的元素对数
        for (int j = 0; j < k / 2; j++) {  // 检查子数组是否满足“快乐数组”条件
            if (a[l + j] != a[l + k - j - 1]) {  // 比较子数组的第j个元素和对称位置的元素
                x += 1;  // 不相等时，x加1
            }
        }

        if (x == 1) {  // 如果仅有一个不对称的元素对，说明这个子数组满足“快乐数组”条件
            s += 1;  // 符合条件的子数组数目加1
        }
        cnt++;  // 总的子数组数目加1
    }

    double res = s * 100.0 / cnt;  // 计算“快乐数组”子数组的比例，转化为百分比形式
    printf("%.2lf%%\n", res);  // 输出结果，保留两位小数，格式化为百分号

    return 0;
}
