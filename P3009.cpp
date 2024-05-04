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
const int N = 1e5 + 10;
int n;
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> dp[i];
    int ans = -inf;
    for (int i = 2; i <= n;i++){
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}