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
const int N = 505, M = 5e4 + 10;
int n1, n2, m;
int e[M], ne[M], h[N], idx;
int match[N];
bool st[N];
int res;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int x)
{
    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = 1;
            if (match[j] == 0 || dfs(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if (dfs(i))
            res++;
    }
    cout << res;
    return 0;
}