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
const int N = 3e5 + 10, M = 6e5 + 10;
int n;
int a[N];
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][20];
LL d[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    depth[0] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 19;k++){
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--){
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
    for (int i = 0; i < n;i++)
        cin >> a[i];
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    for (int i = 0; i < n - 1;i++){
        int p = lca(a[i], a[i + 1]);
        d[a[i]]++, d[a[i + 1]]++, d[p]--;
        if(p!=1)
            d[fa[p][0]]--;
    }
    dfs(1, -1);
    for (int i = 1; i < n;i++)
        d[a[i]]--;
    for (int i = 1; i <= n; i++)
        cout << d[i] << endl;
    return 0;
}