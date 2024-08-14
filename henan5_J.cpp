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
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int t0, t1, t2;
int h[N], e[M], w1[M], w2[M], ne[M], idx;
int dp[N];

void add(int a, int b, int c, int d)
{
    e[idx] = b, ne[idx] = h[a], w1[idx] = c, w2[idx] = d, h[a] = idx++;
}

void solve()
{
    cin >> n >> m;
    cin >> t0 >> t1 >> t2;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d), add(b, a, c, d);
    }
    memset(dp, -1, sizeof dp);
    priority_queue<PII> q; // 1:最晚时间 2: 到哪个点
    q.push({t0, n});
    while (!q.empty())
    {
        auto [t, ver] = q.top();
        q.pop();
        if (dp[ver] != -1)
            continue;
        dp[ver] = t;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            int nt = -1;
            nt = max(nt, min(t1, t) - w1[i]);
            if (t - w1[i] >= t2)
            {
                nt = max(nt, t - w1[i]);
            }
            nt = max(nt, t - w2[i]);
            if (nt >= 0)
                q.push({nt, j});
        }
    }
    cout << dp[1] << endl;
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
        solve();
    }
    return 0;
}
