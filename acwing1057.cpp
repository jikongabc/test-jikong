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
typedef pair<int, PII> PIII;
const int N = 1e5 + 10, M = 110;
int n, m;
int w[N];
int dp[N][M][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> w[i];
    }
    memset(dp, -inf, sizeof dp);
    for (int i = 0; i <= n;i++)
        dp[i][0][0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - w[i]);
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + w[i]);
        }
    }
    int res = 0;
    for (int i = 1; i <= m;i++){
        res = max(res, dp[n][i][0]);
    }
    cout << res;
    return 0;
}