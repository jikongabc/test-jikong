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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 805, M = N * N;
int c, n, m;
int a[N];
int dist[N];
bool st[N];
int e[M], ne[M], w[M], h[M], idx;
int ans = inf;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start)
{
    memset(dist, inf, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
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
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m;
    for (int i = 1; i <= c; i++)
    {
        int num;
        cin >> num;
        a[num]++;
    }
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w), add(b, a, w);
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        if (!a[i])
            continue;
        dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            // cout << dist[j] << ' ';
            sum += a[j] * dist[j];
        }
        // cout << endl;
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}