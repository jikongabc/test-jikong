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
const int mod = 1000000007;
LL dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        dp[i] = (dp[i] + dp[i - 1]) % mod;
        if(i>=3)
            dp[i] = (dp[i] + dp[i - 3]) % mod;
        if(i>=2)
            dp[i] = (dp[i] + dp[i - 2]) % mod;
    }
    cout << dp[n];
    return 0;
}
