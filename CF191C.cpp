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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10, M = 4e5 + 10;
int n, k;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][20];
PII edges[N];
LL d[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k < 20;k++)
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n-1;i++){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        edges[i] = {u, v};
    }
    bfs();
    cin >> k;
    for (int i = 0; i < k;i++){
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        d[a]++, d[b]++, d[p] -= 2;
    }
    dfs(1, -1);
    // for (int i = 1; i <= n;i++)
    //     cout << d[i] << ' ';
    for (int i = 0; i < n-1;i++){
        int a = edges[i].first, b = edges[i].second;
        if(depth[a]>depth[b])
            cout << d[a] << ' ';
        else
            cout << d[b] << ' ';
    }
        return 0;
}