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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, q;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][16];
int maxv[N];
int ask[10010];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int f,int maxn){
    if(u>maxn)
        maxn = u;
    maxv[u] = maxn;
    if(u!=0){
        fa[u][0] = f;
        for (int i = 1; i <= 15; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=f){
            depth[j] = depth[u] + 1;
            dfs(j, u, maxn);
        }
    }
    return;
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int i = 15; i >= 0;i--){
        if(depth[fa[a][i]]>=depth[b])
            a = fa[a][i];
    }
    if(a==b)
        return a;
    for (int i = 15; i >= 0;i--){
        if(fa[a][i]!=fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++){
        int x;
        cin >> x;
        add(i, x), add(x, i);
    }
    cin >> q;
    dfs(0, -1, 0);
    for (int i = 0; i <= n;i++)
        cout << depth[i];
    while (q--)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> ask[i];
        }
        int p = ask[0];
        for (int i = 1; i < m; i++)
            p = lca(p, ask[i]);
        cout << maxv[p] << endl;
    }
    return 0;
}