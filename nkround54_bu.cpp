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
int n;
int a[N];
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n;i++){
            for (int j = max(1, i - a[i] + 1); j <= i;j++){
                dp[j + a[i] - 1] = min(dp[j + a[i] - 1], dp[j - 1] + 1);
            }
        }
        cout << (dp[n] == inf ? -1 : dp[n] )<< endl;
    }
    return 0;
}
