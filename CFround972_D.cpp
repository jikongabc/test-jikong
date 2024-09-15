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
const int N = 1e5 + 10;
string t="narek";
string s[N];
int n, m;
// int dp[N];
// int ndp[N];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> s[i];
    vector<int> dp(5, -inf), ndp;
    // memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n;i++){
        ndp = dp;
        // memcpy(ndp, dp, sizeof dp);
        for (int j = 0; j < 5;j++){
            if(dp[j]==-inf)
                continue;
            int cnt = 0, next = j;
            for (int k = 0; k < m;k++){
                int pos = t.find(s[i][k]);
                if(pos==-1)
                    continue;
                if(pos==next){
                    next = (next + 1) % 5;
                    cnt++;
                }
                else
                    cnt--;
            }
            ndp[next] = max(ndp[next], dp[j] + cnt);
        }
        // memcpy(dp, ndp, sizeof dp);
        dp = ndp;
    }
    int res = 0;
    for (int i = 0; i < 5;i++){
        res = max(res, dp[i] - 2 * i);
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}