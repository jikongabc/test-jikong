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
int h[N];
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> h[i];
        dp[i] = inf;
    }
    dp[n + 1] = inf;
    for (int i = 1; i <= n+1;i++){
        if(i>=3)
            dp[i] = min({dp[i],dp[i - 1], dp[i - 2], dp[i - 3]}) + h[i];
        else if (i >= 2)
            dp[i] = min({dp[i],dp[i - 1], dp[i - 2]}) + h[i];
        else
            dp[i] = min(dp[i], dp[i - 1]) + h[i];
    }
    cout << dp[n + 1];

    return 0;
}