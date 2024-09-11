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
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][16];
int w[N];
int pre[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int p){
    depth[u] = depth[p] + 1;
    if(u!=1){
        fa[u][0] = p;
        for (int i = 1; i <= 15; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=p){
            // depth[j] = depth[u] + 1;
            pre[j] = pre[u] + w[j];
            dfs(j, u);
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
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        w[a]++, w[b]++;
    }
    dfs(1, -1);
    // for (int i = 0; i <= n;i++)
    //     cout << depth[i] << ' ';
    // cout << endl;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        int res = pre[a] + pre[b] - 2 * pre[p] + w[p];
        cout << res << endl;
    }
        return 0;
}