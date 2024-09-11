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
const int N = 5e4 + 10, M = 1e5 + 10;
int n, k;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][20];
int d[N];
int ans;
int res[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    int q[M];
    int hh = 0, tt = 0;
    q[0] = 1;
    depth[0] = 0;
    depth[1] = 1;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 19;k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int i = 19; i >= 0;i--){
        if(depth[fa[a][i]]>=depth[b])
            a = fa[a][i];
    }
    if(a==b)
        return a;
    for (int i = 19; i >= 0;i--){
        if(fa[a][i]!=fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

void dfs(int u,int f){
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=f){
            dfs(j, u);
            d[u] += d[j];
        }
    }
    ans = max(ans, d[u]);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    while(k--){
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        d[a]++, d[b]++, d[p]--;
       if(p!=1)
           d[fa[p][0]]--;
    }
    dfs(1, -1);
    cout << ans;
    return 0;
}