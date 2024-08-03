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
const int N = 205;
int n;
int w[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> w[i];
        w[n + i] = w[i];
    }
    for (int len = 3; len <= n+1;len++){
        for (int i = 1; i + len - 1 <= n * 2; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k < j;k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + w[i] * w[k] * w[j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n;i++){
        res = max(res, dp[i][i + n]);
    }
    cout << res;
    return 0;
}