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
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 5e5 + 10;
int n, m, k, s;
int P, Q;
int c[N];
int w[N];
int h[N], e[N], ne[N], idx;
bool st[N];
int safe[N];
int dist[N];
PII q[N];
int hh = 0, tt = -1;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> qq;
    qq.push({0, 1});
    while (!qq.empty())
    {
        auto t = qq.top();
        qq.pop();
        int ver = t.second;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(safe[j]==-1)
                continue;
            if (dist[j] > dist[ver] + w[j])
            {
                dist[j] = dist[ver] + w[j];
                qq.push({dist[j], j});
            }
        }
    }
    return dist[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> s;
    memset(h, -1, sizeof h);
    cin >> P >> Q;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        q[++tt] = {0, c[i]};
        safe[c[i]] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    while (hh <= tt)
    {
        auto t = q[hh++];
        int dis = t.first, ver = t.second;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dis + 1 <= s && safe[j] == 0)
            {
                safe[j] = 1;
                q[++tt] = {dis + 1, j};
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (safe[i] == -1)
            w[i] = inf;
        else if (safe[i] == 1)
            w[i] = Q;
        else if (safe[i] == 0)
            w[i] = P;
    }
    w[1] = 0;
    w[n] = 0;
    cout << dijkstra();
    return 0;
}