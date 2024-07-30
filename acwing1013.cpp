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
const int N = 20;
int n, m;
int w[N][N];
int res[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j;k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << dp[n][m] << endl;
    int j = m;
    for (int i = n; i;i--){
        for (int k = 0; k <= j;k++){
            if(dp[i][j]==dp[i-1][j-k]+w[i][k]){
                res[i] = k;
                j -= k;
                break;
            }
        }
    }
    for (int i = 1; i <= n;i++)
        cout << i << ' ' << res[i] << endl;

        return 0;
}