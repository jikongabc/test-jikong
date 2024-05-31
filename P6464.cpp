#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 105, M = N * N;
int n, m;
int d[N][N];
int dp[N][N];
int res = inf;

void floyd(){
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}

void solve(int i,int j){
    int dis = 0;
    for (int x = 1; x <= n;x++){
        for (int y = 1; y <= n;y++){
            dp[x][y] = d[x][y];
        }
    }
    dp[i][j] = dp[j][i] = 0;
    for (int x = 1; x <= n;x++){
        for (int y = 1; y <= n;y++){
            dp[x][y] = min(dp[x][y], dp[x][i] + dp[i][y]);
        }
    }
    for (int x = 1; x <= n;x++){
        for (int y = 1; y <= n;y++){
            dp[x][y] = min(dp[x][y], dp[x][j] + dp[j][y]);
        }
    }
    for (int x = 1; x <= n;x++){
        for (int y = x + 1; y <= n;y++){
            dis += dp[x][y];
        }
    }
    res = min(res, dis);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min(d[a][b], w);
    }
    floyd();
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            solve(i, j);
        }
    }
    cout << res;
    return 0;
}