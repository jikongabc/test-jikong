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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int n, m;
int dp[N], g[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dp, -inf, sizeof dp);
    dp[0] = 0;
    g[0] = 1;
    for (int i = 1; i <= n;i++){
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v;j--){
            int maxn = max(dp[j], dp[j - v] + w);
            int s = 0;
            if(maxn==dp[j])
                s = g[j];
            if(maxn==dp[j-v]+w)
                s = (s + g[j - v]) % mod;
            dp[j] = maxn, g[j] = s;
        }
    }
    int maxv = 0;
    for (int i = 0; i <= m;i++){
        maxv = max(maxv, dp[i]);
    }
    int res = 0;
    for (int i = 0; i <= m;i++){
        if(dp[i]==maxv)
            res = (res + g[i]) % mod;
    }
    cout << res;
    return 0;
}