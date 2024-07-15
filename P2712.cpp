#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n;
int e[N], ne[N], h[N], idx;
int d[N];
int q[N];
bool st[N];
int a[N];


void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int topsort()
{
    int cnt = 0;
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[a[i]])
            q[++tt] = a[i];
    while (hh <= tt)
    {
        cnt++;
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0 && st[j])
                q[++tt] = j;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> a[i] >> m;
        st[a[i]] = 1;
        while (m--)
        {
            int y;
            cin >> y;
            add(a[i], y);
            d[y]++;
        }
    }
    int tt = topsort();
    if (tt == n )
        cout << "YES";
    else
        cout << n - tt;
    return 0;
}