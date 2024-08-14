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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e6 + 10, M = 2e6 + 10;
int n, m;
int h[N], rh[N] ,e[M], ne[M], w[M], idx;
int dist1[N];
int dist2[N];
bool st[N];

void add(int *h,int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra1()
{
    memset(st, false, sizeof st);
    memset(dist1, inf, sizeof dist1);
    dist1[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second, dist1anse = t.first;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist1[j] > dist1[ver] + w[i])
            {
                dist1[j] = dist1[ver] + w[i];
                q.push({dist1[j], j});
            }
        }
    }
}
void dijkstra2()
{
    memset(st, false, sizeof st);
    memset(dist2, inf, sizeof dist2);
    dist2[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int ver = t.second, dist2anse = t.first;
        if (st[ver])
            continue;
        st[ver] = 1;
        for (int i = rh[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist2[j] > dist2[ver] + w[i])
            {
                dist2[j] = dist2[ver] + w[i];
                q.push({dist2[j], j});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c), add(rh, b, a, c);
    }
    dijkstra1();
    dijkstra2();
    LL res = 0;
    for (int i = 1; i <= n;i++){
        res += (dist1[i] + dist2[i]);
    }
    cout << res;
    return 0;
}
