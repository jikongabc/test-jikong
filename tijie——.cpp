// #include <iostream>
// #include <algorithm>
// using namespace std;
// using LL = long long;
// const int N = 1e6 + 10;

// LL n, k;
// LL a[N];

// bool check(LL x)
// {
//     LL res = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         res += a[i] / x;
//     }
//     return res >= k;
// }

// int main()
// {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     LL l = 0, r = 100000001;
//     LL mid;
//     while (l<r)
//     {
//         mid = l + r + 1 >> 1;
//         if (check(mid))
//             l = mid;
//         else
//             r = mid - 1;
//     }
//     cout << l << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;
long long n, k, s[10005], ans, l, r, sum, mid;
double s1[10005], t;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s1[i], s[i] = s1[i] * 100, ans = ans + s[i];
    l = 0, r = ans / k + 1;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        ans = 0;
        for (int i = 1; i <= n; i++)
            ans = ans + s[i] / mid;
        if (ans < k)
            r = mid - 1;
        else
            l = mid;
    }
    t = r * 1.00 / 100;
    printf("%.2lf\n", t);
    return 0;
}