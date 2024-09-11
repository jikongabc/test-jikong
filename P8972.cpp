#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long 
using namespace std;
using LL = long long;

const int N = 2e5 + 10, M = 4e5 + 10;
int n, q;
int h[N], e[M], ne[M], idx;
int depth[N];
int fa[N][20];
LL cnt2[N], cnt5[N];
LL two[M], five[M];
LL res2[N], res5[N];

void add(int a, int b, LL c2, LL c5)
{
    e[idx] = b;
    two[idx] = c2;
    five[idx] = c5;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[1] = 1;
    int q[N], hh = 0, tt = 0;
    q[0] = 1;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 19; k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

void get1(int u,int dep,int f){
    depth[u] = dep;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=f)
            get1(j, dep + 1, u);
    }
}

void get2(int u,int f){
    fa[u][0] = f;
    for (int i = 1; i <= log2(depth[u]);i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(j!=f)
            get2(j, u);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--)
    {
        if (depth[fa[a][i]] >= depth[b])
            a = fa[a][i];
    }
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

void dfs(int u, int f,int c2,int c5)
{
    res2[u] = c2, res5[u] = c5;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != f)
        {
            dfs(j, u, c2 + two[i], c5 + five[i]);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        LL c2 = 0, c5 = 0;
        if (!x)
            c2 = c5 = 1e13;
        else{
            while (x % 2 == 0)
                x /= 2, c2++;
            while (x % 5 == 0)
                x /= 5, c5++;
        }
        cnt2[i] = c2;
        cnt5[i] = c5;
    }

    memset(h, -1, sizeof h);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        double w;
        cin >> a >> b >> w;
        int nw = w * 10000 + 1e-5;
        LL c2 = 0, c5 = 0;
        if (!nw)
            c2 = c5 = 1e13;
        else
        {
            while (nw % 2 == 0)
                nw /= 2, c2++;
            while (nw % 5 == 0)
                nw /= 5, c5++;
        }
        add(a, b, c2, c5);
        add(b, a, c2, c5);
    }

    bfs();
    // get1(1, 0, 0);
    // get2(1, 0);
    dfs(1, 0, 0, 0);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        LL dis = depth[a] + depth[b] - 2 * depth[p];
        LL res_1 = res2[a] + res2[b] - 2 * res2[p] + cnt2[a];
        LL res_2 = res5[a] + res5[b] - 2 * res5[p] + cnt5[a];
        LL res = min(res_1, res_2);
        if (res >= dis * 4)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
