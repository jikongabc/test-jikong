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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int d[N];
int ans;
int q[M];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    int hh = 0, tt = 0;
    q[0] = 1;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 16;k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int k = 16; k >= 0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b)
        return a;
    for (int k = 16; k >= 0;k--){
        if(fa[a][k]!= fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dfs(int u,int father){
    int res = d[u];
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=father){
            int s = dfs(j, u);
            if(!s)
                ans += m;
            if(s==1)
                ans++;
            res += s;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bfs();
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        d[a]++, d[b]++, d[p] -= 2;
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
