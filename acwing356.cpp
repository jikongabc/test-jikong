#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1e5 + 10, M = 3e5 + 10;
int n, m;
int p[N];
int h[N], e[M], w[M], ne[M], idx;
int depth[N];
int fa[N][17];
int d1[N][17], d2[N][17];
int q[N];

struct Edge
{
    int a, b, w;
    bool used;
} edges[M];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

LL kruskal()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(edges, edges + m, cmp);
    LL res = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            edges[i].used = true;
        }
    }
    return res;
}

void build()
{
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
        if (edges[i].used)
        {
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            add(a, b, w), add(b, a, w);
        }
}

void bfs()
{
    memset(depth, inf, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    q[0] = 1;
    int hh = 0, tt = 0;
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
                d1[j][0] = w[i], d2[j][0] = -inf;
                for (int k = 1; k <= 16; k++)
                {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    int distance[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
                    d1[j][k] = d2[j][k] = -inf;
                    for (int u = 0; u < 4; u++)
                    {
                        int d = distance[u];
                        if (d > d1[j][k])
                            d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if (d != d1[j][k] && d > d2[j][k])
                            d2[j][k] = d;
                    }
                }
            }
        }
    }
}

int lca(int a, int b, int w)
{
    static int distance[N * 2];
    int cnt = 0;
    if (depth[a] < depth[b])
        swap(a, b);
    for (int k = 16; k >= 0; k--)
    {
        if (depth[fa[a][k]] >= depth[b])
        {
            distance[cnt++] = d1[a][k];
            distance[cnt++] = d2[a][k];
            a = fa[a][k];
        }
    }
    if (a != b)
    {
        for (int k = 16; k >= 0; k--)
        {
            if (fa[a][k] != fa[b][k])
            {
                distance[cnt++] = d1[a][k];
                distance[cnt++] = d2[a][k];
                distance[cnt++] = d1[b][k];
                distance[cnt++] = d2[b][k];
                a = fa[a][k], b = fa[b][k];
            }
        }
        distance[cnt++] = d1[a][0];
        distance[cnt++] = d1[b][0];
    }
    int dist1 = -inf, dist2 = -inf;
    for (int i = 0; i < cnt; i++)
    {
        int d = distance[i];
        if (d > dist1)
            dist2 = dist1, dist1 = d;
        else if (d != dist1 && d > dist2)
            dist2 = d;
    }
    if (w > dist1)
        return w - dist1;
    if (w > dist2)
        return w - dist2;
    return inf;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    LL sum = kruskal();
    build();
    bfs();
    LL res = 1e18;
    for (int i = 0; i < m; i++)
    {
        if (!edges[i].used)
        {
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            res = min(res, sum + lca(a, b, w));
        }
    }
    cout << res << endl;
    return 0;
}