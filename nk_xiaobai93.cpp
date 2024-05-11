#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
const int mod = 998244353;
int n;
ULL ans1, ans2;
string a, b;

// vector<int> mul(vector<int> &a, vector<int> &b)
// {
//     vector<int> c(a.size() + b.size(), 0);

//     for (int i = 0; i < a.size(); i++)
//     {
//         for (int j = 0; j < b.size(); j++)
//         {
//             c[i + j] += a[i] * b[j];
//             c[i + j + 1] += c[i + j] / 10;
//             c[i + j] %= 10;
//         }
//     }

//     while (c.size() > 1 && c.back() == 0)
//     {
//         c.pop_back();
//     }

//     return c;
// }

// vector<int> div(vector<int> &A, int b, int r)
// {
//     vector<int> C;
//     r = 0;
//     for (int i = A.size() - 1; i >= 0; i--)
//     {
//         r = r * 10 + A[i];
//         C.push_back(r / b);
//         r %= b;
//     }
//     reverse(C.begin(), C.end());
//     while (C.size() > 1 && C.back() == 0)
//         C.pop_back();
//     return C;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     cin >> a >> b;
//     for (int i = 0; i < n;i++){
//         if(a[i]>b[i])
//             swap(a[i], b[i]);
//     }
//     vector<int> A, B, C, D;
//     for (int i = n - 1; i >= 0;i--){
//         A.push_back(a[i] - '0');
//     }
//     for (int i = n - 1; i >= 0;i--){
//         B.push_back(b[i] - '0');
//     }
//     C = mul(A, B);
//     // for (int i = C.size() - 1; i >= 0;i--){
//     //     cout << C[i];
//     // }
//     // cout << endl;
//     // for (int i = 0; i < C.size();i++){
//     //     D.push_back(C[C.size() - 1 - i]);
//     // }
//     // for (int i = 0; i < C.size();i++){
//     //     cout << D[i];
//     // }
//         // for (int i = 0; i < n; i++)
//         // {
//         //     ans1 = ((ULL)ans1 * 10 + (ULL)([i] - '0') % mod);
//         //     ans2 = ((ULL)ans2 * 10 + (ULL)([i] - '0') % mod);
//         // }
//     // int r;
//     // auto ans = div(C, mod, r);
//     // for (int i = ans.size() - 1; i >= 0;i--){
//     //     cout << ans[i];
//     // }
//     ULL ans = 0;
//     for (int i = C.size()-1; i >=0 ; i--)
//     {
//         ans = (ULL)ans * 10 + (ULL)(C[i] % mod);
//     }
//     cout << ans % mod;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// const int MOD = 998244353;

// 快速幂算法，计算x^y % mod
ULL quickPow(ULL x, ULL y, ULL mod)
{
    ULL res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

// 将字符串转换为整数，考虑模运算
ULL strToIntMod(const string &s, ULL mod)
{
    ULL result = 0;
    for (char c : s)
    {
        result = (result * 10 + (c - '0')) % mod;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // 将两个数字按从小到大排序
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }

    // 使用快速幂算法计算乘积
    ULL ans = strToIntMod(a, mod) * strToIntMod(b, mod) % mod;

    cout << ans%mod << endl;

    return 0;
}
