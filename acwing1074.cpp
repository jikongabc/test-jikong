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
const int N = 205;
int n, m;
int dp[N][N];
int h[N], e[N], ne[N], w[N], idx;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int fa){
    for (int i = h[u]; ~i;i=ne[i]){
        int t = e[i];
        if(t==fa)
            continue;
        dfs(t, u);
        for (int j = m; j >= 1;j--){
            for (int k = 0; k < j;k++){
                dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[t][k] + w[i]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << dp[1][m];
    return 0;
}