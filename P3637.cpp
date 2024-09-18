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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 5e5 + 10, M = 1e6 + 10;
int n, m;
int h[N], sh[N], e[M], ne[M], idx;
int w[N], sw[N];
int start, cnt, sstart;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
bool has_bar[N];
bool has_has_bar[N];
int dp[N];

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j])
            low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u])
    {
        int y;
        scc_cnt++;
        do
        {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sw[scc_cnt] += w[y];
            if (has_bar[y])
                has_has_bar[scc_cnt] = true;
            if (y == start)
                sstart = scc_cnt;
        } while (y != u);
    }
}

void bfs()
{
    queue<int> q;
    dp[sstart] = sw[sstart];
    q.push(sstart);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = sh[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dp[j] < dp[t] + sw[j])
            {
                dp[j] = dp[t] + sw[j];
                q.push(j);
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
    memset(sh, -1, sizeof sh);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(h, a, b);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cin >> start >> cnt;
    while (cnt--)
    {
        int x;
        cin >> x;
        has_bar[x] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if (a != b)
                add(sh, a, b);
        }
    }
    bfs();
    int res = 0;
    for (int i = 1; i <= scc_cnt; i++)
    {
        if (has_has_bar[i])
            res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}