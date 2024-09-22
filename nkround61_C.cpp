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
const int N = 1e5 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const string op = "URDL";
int n, x, y;
string s;
unordered_map<char, int> id;

void solve()
{
    cin >> n >> x >> y;
    cin >> s;
    int cnt[4];
    int x1 = 0, y11 = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = id[s[i]];
        cnt[pos]++;
        x1 += dx[pos], y11 += dy[pos];
    }
    int cx = x - x1, cy = y - y11; // 差值
    if (cx > 0 && cx > cnt[2] || cx < 0 && abs(cx) > cnt[0] || cy > 0 && cy > cnt[1] || cy < 0 && abs(cy) > cnt[3])
    {
        cout << "NO\n";
        return;
    }
    cout << "YES ";
    LL res = 0;
    int pos1, pos2;
    if (cx > 0)
        pos1 = 2;
    else
        pos1 = 0;
    if (cy > 0)
        pos2 = 1;
    else
        pos2 = 3;
    int a = abs(cx), b = abs(cy);
    // res += C(cnt[pos1], a) * C(cnt[pos2], b);
    for (int i = 0; i < n; i++)
    {
        if (id[s[i]] == pos1)
        {
            if (a)
            {
                a--;
                continue;
            }
        }
        if (id[s[i]] == pos2)
        {
            if (b)
            {
                b--;
                continue;
            }
        }
        cout << s[i];
    }
    res = 4;
    // cout << ' ' << res;
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < 4; i++)
    {
        id[op[i]] = i;
    }
    while (T--)
    {
        solve();
    }
    return 0;
}