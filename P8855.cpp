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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 3e4 + 10, M = 1e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][16];
int g[N];
int dist[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    int q[M];
    int hh = 0, tt = 0;
    depth[1] = 1;
    depth[0] = 0;
    q[0] = 1;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k < 16; k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
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
        if(fa[a][i]!=fa[b][i]) {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    cin >> m;
    int res = 0;
    int p = 1;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        res += (depth[p] + depth[v] - 2 * depth[lca(p, v)]);
        p = v; 
    }
    cout << res;
    return 0;
}