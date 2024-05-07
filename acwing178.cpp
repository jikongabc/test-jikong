#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<int, PII> PIII;
const int N = 1010, M = 200010;
int n, m, S, T, k;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, T});
    memset(dist, inf, sizeof dist);
    dist[T] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = rh[ver]; ~i; i = ne[i])
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

int astar()
{
    priority_queue < PII, vector<PIII>, greater<PIII> > q;
    q.push({dist[S], {0, S}});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second.second, distance = t.second.first;
        cnt[ver]++;
        if (cnt[T] == k)
            return distance;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (cnt[j] < k)
                q.push({distance + w[i] + dist[j], {distance + w[i], j}});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin >> S >> T >> k;
    if (S == T)
        k++;
    dijkstra();
    cout << astar() << endl;
    return 0;
}