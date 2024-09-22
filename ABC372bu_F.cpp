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
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10, M = 4e5 + 10;
const int mod = 998244353;
int n, m, k;
PII edges[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
    }
    vector<int> dp(n + k, 0);
    int l = k;
    dp[k] = 1;
    for (int step = 0; step < k;step++){
        vector<PII> add;
        for (int i = 0; i < m;i++){
            int a = edges[i].first, b = edges[i].second;
            add.push_back({b, dp[l + a]});
        }
        l--;
        dp[l] = dp[l + n];
        for(const auto &t : add){
            int b = t.first, val = t.second;
            dp[b + l] = (dp[b + l] + val) % mod;
        }
        // vector<int> rdp(n, 0);
        // for (int i = 0; i < n;i++){
        //     rdp[(i + 1) % n] = (rdp[(i + 1) % n] + dp[i]) % mod;
        // }
        // for (int i = 0; i < m;i++){
        //     int a = edges[i].first, b = edges[i].second;
        //     rdp[b] = (rdp[b] + dp[a]) % mod;
        // }
        // dp = rdp;
    }
    int res = 0;
    for (int i = 0; i < n;i++){
        res = (res + dp[i]) % mod;
    }
    cout << res << endl;

    return 0;
}