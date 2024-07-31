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
int n, m;
int v[N], w[N], p;
int dp[N][N];
int e[N], ne[N], h[N], idx;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    for (int i = v[u]; i <= m;i++)
        dp[u][i] = w[u];
    for (int i = h[u]; ~i;i=ne[i]){
        int son = e[i];
        dfs(son);
        for (int j = m; j >= v[u];j--){
            for (int k = 0; k <= j - v[u];k++){
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int root;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        cin >> v[i] >> w[i] >> p;
        if(p==-1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);
    cout << dp[root][m];
    return 0;
}