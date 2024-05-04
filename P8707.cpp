#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 105;
int n, m;
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        dp[i][1] = 1;
    for (int j = 1; j <= m;j++)
        dp[1][j] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if(i%2==0 && j%2==0)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m];
    return 0;
}