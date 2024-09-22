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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10;

LL f(LL l)
{
    if (l % 2 == 0)
        return (l * l) / 4;
    else
        return (l * l - 1) / 4;
}

LL computeS(LL x, LL y, LL n)
{
    LL left = 0, right = 0, mid = 0;
    if (x >= 1)
        left = (x - 1) * x / 2;
    else
        left = (1 - x) * (0) / 2;

    if (y <= n)
        right = (n - y) * (n - y + 1) / 2;
    else
        right = (y - n - 1) * (y - n) / 2;

    LL l = y - x;
    LL cnt = min(n, y) - max(1LL, x) + 1;
    if (cnt > 0)
    {
        LL l_eff = cnt - 1;
        if (l_eff % 2 == 0)
            mid = (l_eff / 2) * ((l_eff / 2) + 1);
        else
            mid = ((l_eff + 1) / 2) * ((l_eff + 1) / 2);
    }

    LL S = left + mid + right;
    return S;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        LL n, l;
        cin >> n >> l;
        LL t;
        if (l <= n)
            t = (n - l + 1) / 2;
        else
            t = (1 - l) / 2;

        LL bestS = -1;
        LL bestX = t, bestY = t + l;

        for (LL dx = -n; dx <= n; ++dx)
        {
            LL x = t + dx;
            LL y = x + l;
            LL S = 0;
            S = computeS(x, y, n);
            if (bestS == -1 || S < bestS)
            {
                bestS = S;
                bestX = x;
                bestY = y;
            }
        }

        cout << bestX << ' ' << bestY << ' ' << bestS << "\n";
    }

    return 0;
}
