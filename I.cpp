#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> PII;
const int N = 2e5 + 10;
int n, m;
LL e[N], ne[N], h[N], w[N], idx;
LL dist[N];
LL dist1[N];
bool st[N];

void add(LL a, LL b, LL c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

LL dijkstra()
{
    for (int i = 0; i <= n;i++){
        dist[i] = dist1[i] = 1e18;
    }
        // memset(dist, inf, sizeof dist);
        // memset(dist1, inf, sizeof dist1);
        priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        LL ver = t.second, distance = t.first;
        if (distance > dist1[ver])
            continue;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            LL j = e[i];
            LL cost = distance + w[i];
            if (dist[j] > cost)
            {
                dist[j] = cost;
                q.push({dist[j], j});
            }
            if (dist1[j] > cost && cost > dist[j])
            {
                dist1[j] = cost;
                q.push({dist1[j], j});
            }
        }
    }
    return dist1[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m;
        while (m--)
        {
            LL a, b, w;
            cin >> a >> b >> w;
            add(a, b, w), add(b, a, w);
        }
        cout << dijkstra() << endl;
    }
    return 0;
}