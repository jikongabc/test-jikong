#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 100010;
int n, m;
int t[N];
int sum[N];
int dp[N];
// dp[i-1][j]
// dp[i-1][j-i]+sum[i]
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        dp[i] = inf;
        cin >> t[i];
        sum[i] = sum[i - 1] + t[i];
    }
    for (int i = 1; i <= n; i++)
        sum[i] += 2 * m;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            dp[j] = min(dp[j], dp[j - i] + sum[i]);
        }
        }
    cout << dp[n] - m;
    return 0;
}