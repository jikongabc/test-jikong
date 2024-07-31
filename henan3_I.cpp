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
#define inf 1e18
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n, m, k;
int e[N], ne[N], w[N], h[N], idx;
LL dist[N];
bool st[N];
int sst[N];

void add(int a,int b,int c,int d){
    e[idx] = b, sst[idx] = d, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

LL dijkstra1(int start,int end1)//随意走
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second, distanse = t.first;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[end1];
}

LL dijkstra2(int start, int end1) // 只能走1
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second, distanse = t.first;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(sst[i]==0)
                continue;
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[end1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, w, pd;
        cin >> a >> b >> w >> pd;
        add(a, b, w, pd), add(b, a, w, pd);
    }
    LL res1 = dijkstra2(1, n);
    LL res2 = dijkstra2(1, k);
    LL res3 = dijkstra1(k, n);
    LL res = min(res1, res2 + res3);
    if(res>=inf)
        cout << -1;
    else
        cout << res;
    return 0;
}