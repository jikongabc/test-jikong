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
const int N = 10010, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int depth[N];
int fa[N][16];
int q[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    int hh = 0, tt = -1;
    memset(depth, inf, sizeof depth);
    q[++tt] = 1;
    depth[1] = 1, depth[0] = 0;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                dist[j] = dist[t] + w[i];
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 14; k++)
                {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = 14; i >= 0; i--)
    {
        if (depth[fa[a][i]] >= depth[b])
            a = fa[a][i];
    }
    if (a == b)
        return a;
    for (int i = 14; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    }
    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    bfs();
    int res;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        res = dist[a] + dist[b] - dist[p] * 2;
        cout << res << endl;
    }
    return 0;
}
