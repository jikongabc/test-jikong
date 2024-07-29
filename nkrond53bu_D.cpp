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
const int N = 5005;
int n, m;
int a[55][55];
int dp[N];
int g[N];
int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    cin >> t;
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            for (int k = 5000; k >= 0; k--){
                g[k + a[i][j]] |= dp[k];
            }
        }
        swap(g, dp);
        for (int k = 0; k <= 5000;k++){
            g[k] = 0;
        }
    }
    int res = inf;
    for (int i = 0; i <= 5000;i++){
        if(dp[i])
            res = min(res, abs(t-i));
    }
    cout << res;
    return 0;
}