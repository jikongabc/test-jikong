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
const int N = 2e4 + 10;
int n;
int h[N], e[N], w[N], ne[N], idx;
int d1[N], d2[N], p[N], up[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u,int fa){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j==fa)
            continue;
        int d = dfs_d(j, u) + w[i];
        if(d>=d1[u]){
            d2[u] = d1[u];
            d1[u] = d;
            p[u] = j;
        }
        else if(d>d2[u])
            d2[u] = d;
    }
    return d1[u];
}

void dfs_u(int u,int fa){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j==fa)
            continue;
        if(p[u]==j)
            up[j] = max(up[u], d2[u]) + w[i];
        else
            up[j] = max(up[u], d1[u]) + w[i];
        dfs_u(j, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs_d(1, -1);
    dfs_u(1, -1);
    int res = inf;
    for (int i = 1; i <= n;i++){
        res = min(res, max(d1[i],up[i]));
    }
    cout << res;
    return 0;
}