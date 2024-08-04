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
const int N = 1510;
int n;
int e[N], ne[N], h[N], idx;
int w[N];
int dp[N][3];//1：被根节点看到  2：被子节点看到 3：自己放
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    dp[u][2] = w[u];
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        dfs(j);
        dp[u][0] += min(dp[j][1], dp[j][2]);
        dp[u][2] += min(min(dp[j][0], dp[j][1]), dp[j][2]);
    }
    dp[u][1] = inf;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        dp[u][1] = min(dp[u][1], dp[j][2] + dp[u][0] - min(dp[j][1], dp[j][2]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n;i++){
        int id, cost, cnt;
        cin >> id >> cost >> cnt;
        w[id] = cost;
        while(cnt--){
            int ver;
            cin >> ver;
            add(id, ver);
            st[ver] = true;
        }
    }
    int root = 1;
    while(st[root])
        root++;
    dfs(root);
    cout << min(dp[root][1], dp[root][2]);
    return 0;
}