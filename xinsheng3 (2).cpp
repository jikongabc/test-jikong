#include <stdio.h>
#include <math.h>
#include <string.h>
int a[4][4];

int main(){
	int a[3][3]; // 使用a作为3x3二维数组的名称
    int sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8;
    // 读取九宫格的数字
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 计算行和列的和
    sum1 = a[0][0] + a[0][1] + a[0][2]; // 第一行
    sum2 = a[1][0] + a[1][1] + a[1][2]; // 第二行
    sum3 = a[2][0] + a[2][1] + a[2][2]; // 第三行

    sum4 = a[0][0] + a[1][0] + a[2][0]; // 第一列
    sum5 = a[0][1] + a[1][1] + a[2][1]; // 第二列
    sum6 = a[0][2] + a[1][2] + a[2][2]; // 第三列

    sum7 = a[0][0] + a[1][1] + a[2][2]; // 主对角线
    sum8 = a[0][2] + a[1][1] + a[2][0]; // 副对角线

    // 判断是否满足条件
    if (sum1 == sum2 && sum2 == sum3 && sum3 == sum4 && sum4 == sum5 && sum5 == sum6 && sum6 == sum7 && sum7 == sum8) {
        printf("YES.\n");
    } else {
        printf("NO.\n");
    }
	return 0;
}