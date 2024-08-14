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
const int N = 1e6 + 10;
int n, m, t, k, dp[N][40];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i][0];
    t = log(n) / log(2);

    for (int j = 1; j <= t; j++) 
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        k = log(r - l + 1) / log(2);
        cout << max(dp[l][k], dp[r - (1 << k) + 1][k]) << endl;
    }

    return 0;
}
