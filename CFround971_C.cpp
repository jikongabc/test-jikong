#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    x = (x + k - 1) / k;
    y = (y + k - 1) / k;
    int res = max(x * 2 - 1, y * 2);
    cout << res << endl;
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
        solve();
    }
    return 0;
}