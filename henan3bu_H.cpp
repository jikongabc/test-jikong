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
typedef pair<int, PII> PIII;
const int N = 1e3 + 10;
int n, m, h;
// x, y, 体力 -> 魔法次数
int w[N][N];

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> w[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(h + 1, inf)));
    dp[1][1][h] = 0; 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = h; k > 0; k--){
                // 从上方转移
                if (i > 1){
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1); // 使用魔法
                    if (k > w[i][j]){
                        dp[i][j][k - w[i][j]] = min(dp[i][j][k - w[i][j]], dp[i - 1][j][k]); // 不使用魔法
                        
                    }
                }
                // 从左方转移
                if (j > 1){
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k] + 1); // 使用魔法
                    if (k > w[i][j]){
                        dp[i][j][k - w[i][j]] = min(dp[i][j][k - w[i][j]], dp[i][j - 1][k]); // 不使用魔法
                    }
                }
            }
        }
    }
    int res = inf;
    for (int k = 1; k <= h; k++){
        res = min(res, dp[n][m][k]);
    }
    cout << res << endl;
    return 0;
}
