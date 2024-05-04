#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
int n;
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        dp[i] = inf;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = min({dp[i], dp[i / 2] + 1, dp[i - 1] + 1});
        else
            dp[i] = dp[i - 1] + 1;
        }
    cout << dp[n];
    return 0;
}