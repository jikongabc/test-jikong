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
const int N = 1e7 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
LL dist[N];
bool st[N];

struct node{
    int a, b, w;
} p[N];

LL ans;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(st, false, sizeof st);
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second;
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        p[i] = {a, b, w};
        add(a, b, w);
    }
    dijkstra();
    for (int i = 1; i <= n;i++){
        ans += dist[i];
    }
    memset(st, false, sizeof st);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++){
        int a = p[i].b, b = p[i].a, w = p[i].w;
        add(a, b, w);
    }
    dijkstra();
    for (int i = 1; i <= n;i++)
        ans += dist[i];
    cout << ans;
    return 0;
}