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
const int N = 1e5 + 10;
int n;
int w[N];
int dp[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> w[i];
    dp[0][0] = dp[0][1] = -inf;
    dp[0][2] = 0;
    for (int i = 1; i <= n;i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - w[i]);
        dp[i][1] = dp[i - 1][0] + w[i];
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
    }
    cout << max(dp[n][1], dp[n][2]);
    return 0;
}