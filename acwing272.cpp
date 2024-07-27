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
const int N = 3005;
int a[N], b[N];
int dp[N][N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    for (int i = 1; i <= n;i++){
        int maxn = 1;
        for (int j = 1; j <= n;j++){
            dp[i][j] = dp[i - 1][j];
            if(a[i]==b[j])
                dp[i][j] = max(dp[i][j], maxn);
            if(b[j]<a[i])
                maxn = max(maxn, dp[i][j] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        res = max(res, dp[n][i]);
    }
    cout << res;
    return 0;
}