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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 2e5 + 10, M = 4e5 + 10;
int n;
int h[N], e[M], ne[M], w1[M], w2[M], cnt[M], idx;
int depth[N];
int fa[N][40];
int d[N];
int res;

void add(int a,int b,int c,int d){
    e[idx] = b, w1[idx] = c, w2[idx] = d, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[1] = 1;
    depth[0] = 0;
    queue<int> q;
    // int q[M];
    // int hh = 0, tt = 0;
    // q[0] = 1;
    q.push(1);
    while(!q.empty()){
        // int t = q[hh++];
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                // q[++tt] = j;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 35;k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

void dfs(int u,int f){
    int t;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=f){
            dfs(j, u);
            d[u] += d[j];
        }
        else
            t = i;
    }   
    if(w1[t]*d[u]<w2[t])
        res += w1[t] * d[u];
    else
        res += w2[t];
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int i = 35; i >= 0;i--){
        if(depth[fa[a][i]]>=depth[b])
            a = fa[a][i];
    }
    if(a==b)
        return a;
    for (int i = 35; i >= 0;i--){
        if(fa[a][i]!=fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d), add(b, a, c, d);
    }
    bfs();
    for (int i = 1; i < n;i++){
        int p = lca(i, i + 1);
        d[i]++, d[i + 1]++, d[p] -= 2;
    }
    dfs(1, -1);
    cout << res;
    return 0;
}