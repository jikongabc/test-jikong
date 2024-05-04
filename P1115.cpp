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
int a[N];
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    for (int i = 1; i <= n;i++){
        dp[i] = max(dp[i], dp[i - 1] + a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}