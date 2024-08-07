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
const int N = 305;
int s[N];
int dp[N][N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int len = 2; len <= n;len++){
        for (int i = 1; i + len - 1 <= n;i++){
            int j = i + len - 1;
            dp[i][j] = inf;
            for (int k = i; k < j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}