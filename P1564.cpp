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
const int N = 3005;
int n, m;
int a[N], b[N];
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]==2)
            a[i] = -1;
        b[i] = b[i - 1] + a[i];
    }
    memset(dp, inf, sizeof dp);
    dp[0] = 0, dp[1] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i; j++){
            if (abs(b[i] - b[j - 1]) <= m || abs(b[i] - b[j - 1])==i-j+1)
                dp[i] = min(dp[i], dp[j-1] + 1);
        }
    }
    cout << dp[n];
    return 0;
}