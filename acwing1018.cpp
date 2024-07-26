// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <cmath>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// typedef pair<int, PII> PIII;
// const int N = 105;
// int n;
// int w[N][N];
// int dp[N][N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= n;j++){
//             cin >> w[i][j];
//         }
//     }
//     for (int i = 1; i <= n;i++){
//         for (int j = 1; j <= n;j++){
//             if (i == 1 && j == 1)
//                 dp[i][j] = w[i][j];
//             else
//                 dp[i][j] = inf;
//                 if(i>1)
//                     dp[i][j] = min(dp[i][j], dp[i - 1][j] + w[i][j]);
//                 if(j>1)
//                     dp[i][j] = min(dp[i][j], dp[i][j - 1] + w[i][j]);
//         }
//     }
//     cout << dp[n][n];
//     return 0;
// }

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
const int N = 105;
int n;
int w[N][N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, inf, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = w[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + w[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}