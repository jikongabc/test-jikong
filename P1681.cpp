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
const int N = 2005;
int n, m;
int p[N][N];
int dp[N][N][2];
int b[N][N];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
            // if(i%2==j%2)
            //     p[i][j] = p[i][j] ^ 1;
            // b[i][j] = p[i][j] ^ 1;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(p[i][j]==1){
                dp[i][j][1] = min(dp[i - 1][j][0], min(dp[i][j - 1][0], dp[i - 1][j - 1][1])) + 1;
                ans = max(ans, dp[i][j][1]);
            }
            else{
                dp[i][j][0] = min(dp[i - 1][j][1], min(dp[i][j - 1][1], dp[i - 1][j - 1][0])) + 1;
                ans = max(ans, dp[i][j][0]);
            }
        }
    }
    cout << ans;
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << p[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << b[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}