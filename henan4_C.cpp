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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
const int mod = 998244353;
int n, m;
int a[N];
LL dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    m -= sum;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= j; k++)
            {
                dp[j] = (dp[j] + dp[j - k]) % mod;
            }
        }
    }
    LL res = 0;
    for (int i = 0; i <= m; i++)
    {
        res = (res + dp[i]) % mod;
    }
    cout << res;
    return 0;
}

// dp[i][j] : 到第i个岗位，已经分配了j个志愿者的方案数
// 第i个岗位分k个志愿者
// dp[i][j] += dp[i - 1][j - k]