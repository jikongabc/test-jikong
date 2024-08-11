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
const int N = 2e5 + 10;
int n, k;
PII f[N];
LL dp[N][15];//dp[i][j]->从i个函数中选，已经选了j层的函数值

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> f[i].first >> f[i].second;
    }
    sort(f + 1, f + 1 + n, [&](auto a, auto b)
         { return a.second * (1 - b.first) < b.second * (1 - a.first); });
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= k;j++){
            dp[i][j] = -1e16;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= k;j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);//不选第i个
            if(j)
                dp[i][j] = max(dp[i][j], f[i].first * dp[i - 1][j - 1] + f[i].second); // 选第i个
        }
    }
    cout << dp[n][k];
    return 0;
}
