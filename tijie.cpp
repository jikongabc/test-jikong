
// #include<iostream>
// using namespace std;

// int w0, w, m;
// double sum;

// int check(double mid)
// {
//     sum = w0;
//     for (int i = 1; i <= m; i++) // 循环 m 次，模拟 m 个月的还款过程
//     {
//         sum = sum + sum * mid - w;
//     }
//     if (sum > 0) // 如果最后金额大于 0，说明利率太高，无法在 m 个月内还清
//         return true; 
//     return false;
// }

// int main()
// {
//     cin >> w0 >> w >> m;

//     double l = 0, r = 500; // 答案范围尽量开大些
//     while (r - l > 1e-5)   // 精度保证
//     {
//         double mid = (l + r) / 2;
//         if (check(mid))
//             r = mid; 
//         else
//             l = mid;
//     }
//     printf("%.1f", l * 100);//保留小数用printf
//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int h[N];
int w[N];

bool check(int x)
{ 
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (h[i] / x) * (w[i] / x);
    if (sum >= k)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    int l = 1, r = 100002;
    while (l < r)
    { 
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}