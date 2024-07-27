// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <cmath>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// typedef pair<int, PII> PIII;
// const int N = 1e6 + 10;
// int n, q;
// string a, b;

// int pre_a[N][30];
// int pre_b[N][30];

// void solve()
// {
//     memset(pre_a, 0, sizeof pre_a);
//     memset(pre_b, 0, sizeof pre_b);
//     cin >> n >> q;
//     cin >> a >> b;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j < 26; j++)
//         {
//             pre_a[i][j] = pre_a[i - 1][j];
//             pre_b[i][j] = pre_b[i - 1][j];
//         }
//         pre_a[i][a[i - 1] - 'a']++;
//         pre_b[i][b[i - 1] - 'a']++;
//     }

//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--, r--;

//         int res = 0;
//         for (int i = 0; i < 26; i++)
//         {
//             int aa = pre_a[r + 1][i] - pre_a[l][i];
//             int bb = pre_b[r + 1][i] - pre_b[l][i];
//             res += abs(aa - bb);
//         }
//         cout << res / 2 << endl;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }

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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;

vector<vector<int>> cre(const string &s)
{
    int n = s.size();
    vector<vector<int>> pre(n, vector<int>(26, 0));
    pre[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][s[i] - 'a']++;
    }
    return pre;
}

vector<int> get(const vector<vector<int>> &pre, int l, int r)
{
    vector<int> v(26, 0);
    if (l == 0)
    {
        v = pre[r];
    }
    else
    {
        for (int i = 0; i < 26; ++i)
        {
            v[i] = pre[r][i] - pre[l - 1][i];
        }
    }
    return v;
}

int solve(const vector<int> &vA, const vector<int> &vB)
{
    int res = 0;
    for (int i = 0; i < 26; ++i)
    {
        res += abs(vA[i] - vB[i]);
    }
    return res / 2; 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        auto preA = cre(a);
        auto preB = cre(b);

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--; 
            auto vA = get(preA, l, r);
            auto vB = get(preB, l, r);
            int result = solve(vA, vB);
            cout << result << endl;
        }
    }
    return 0;
}
