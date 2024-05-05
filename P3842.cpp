#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 2e4 + 10;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
int p[N][2];
int dp[N][2];

int dis(int a,int b){
    return abs(a - b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> p[i][0] >> p[i][1];
    }
    dp[1][1] = p[1][1] - 1, dp[1][0] = dp[1][1] + p[1][1] - p[1][0];
    for (int i = 2; i <= n;i++){
        // dp[i][0] = min(dp[i - 1][0] + p[i][1] - p[i - 1][0] + p[i][1] - p[i][0], dp[i - 1][1] + p[i - 1][1] - p[i][0]) + 1;
        // dp[i][1] = min(dp[i - 1][0] + p[i][1] - p[i - 1][0], dp[i - 1][1] + p[i - 1][1] - p[i][0] + p[i][1] - p[i][0]) + 1;
        dp[i][0] = min(dp[i - 1][0] + dis(p[i - 1][0], p[i][1]) + dis(p[i][0], p[i][1]), dp[i - 1][1] + dis(p[i - 1][1], p[i][1]) + dis(p[i][0], p[i][1])) + 1;
        dp[i][1] = min(dp[i - 1][0] + dis(p[i - 1][0], p[i][0]) + dis(p[i][0], p[i][1]), dp[i - 1][1] + dis(p[i - 1][1], p[i][0]) + dis(p[i][0], p[i][1])) + 1;
    }
    // cout << min(dp[n][0] + n - p[n][0], dp[n][1] + p[n][1] - p[n][0] + n - p[n][0]);
    cout << min(dp[n][0] + dis(p[n][0], n), dp[n][1] + dis(p[n][1], n));
    return 0;
}
