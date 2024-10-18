#include <stdio.h>
#include <math.h>

int count_factors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++; // ����i
            if (i != n / i) {
                cnt++; // ����n/i
            }
        }
        if (cnt > 4) {
            return 5; // ����4�������Ͳ��ü���������
        }
    }
    return count;
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (count_factors(i) <= 4) {
            res++;
        }
    }
    printf("%d\n", res);
    
    return 0;
}

