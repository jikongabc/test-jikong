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
const int N = 110;
int n, m;
int p[N][N];
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(p[i][j]==1){
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}

//dp[i][j]==min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1
