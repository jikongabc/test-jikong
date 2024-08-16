#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 4e4 + 10;
int n, m;
int fa[N];
int res[M];
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int st[N];
vector<PII> query[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void dfs(int u,int fa){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j==fa)
            continue;
        dist[j] = dist[u] + w[i];
        dfs(j, u);
    }
}

void tarjan(int u){
    st[u] = 1;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(st[j])
            continue;
        tarjan(j);
        fa[j] = u;
    }
    for(auto i:query[u]){
        int ver = i.first, op = i.second;
        if(st[ver]==2)
            res[op] = dist[u] + dist[ver] - 2 * dist[find(ver)];
    }
    st[u] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    dfs(1, -1);
    tarjan(1);
    for (int i = 0; i < m; i++)
        cout << res[i] << endl;
    return 0;
}
