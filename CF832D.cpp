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
int n, q;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][20];
int d[N];
int cnt;

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

int solve(int a,int b,int c){
    // memset(d, 0, sizeof d);
    int p1 = lca(a, c);
    int p2 = lca(b, c);
    int p3 = lca(a, b);
    int len1 = depth[a] + depth[c] - 2 * depth[p1];
    int len2 = depth[b] + depth[c] - 2 * depth[p2];
    int len3 = depth[a] + depth[b] - 2 * depth[p3];
    int res = (len1 + len2 - len3) / 2 + 1;
    // d[a]++, d[c]++, d[p]--;
    // if(p!=1)
    //     d[fa[p][0]]--;
    // p = lca(b, c);
    // d[b]++, d[c]++, d[p]--;
    // if(p!=1)
    //     d[fa[p][0]]--;
    // dfs(1, -1);
    // for (int i = 1; i <= n;i++){
    //     // cout << d[i] << ' ';
    //     if (d[i] >= 2)
    //         cnt++;
    // }
    // cout << endl;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n;i++){
        int x;
        cin >> x;
        add(i, x), add(x, i);
    }
    bfs();
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int res;
        res = max({solve(a, b, c), solve(a, c, b), solve(b, c, a)});
        cout << res << endl;
    }

    return 0;   
}