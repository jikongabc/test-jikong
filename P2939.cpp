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
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 4e5 + 10, M = 5e6 + 10;
int n, m, k;
int e[M], h[N], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[n + k * n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        for (int i = 1; i <= k; i++)
        {
            add(a + (i - 1) * n, b + n * i, 0), add(b + (i - 1) * n, a + n * i, 0);
            add(a + i * n, b + i * n, c), add(b + i * n, a + i * n, c);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        add(n + (i - 1) * n, n + i * n, 0);
    }
    int res=dijkstra();
    if(res==inf)
        cout << -1;
    else
        cout << res;
    return 0;
}
