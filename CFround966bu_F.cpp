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
const int N = 1e3 + 10;
int n, k;
int dp[N];//dp[i] -> 得到i分所需的最小体积

void solve(){
    cin >> n >> k;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        if(a>b)
            swap(a, b);
        for (int j = k; j >= 0;j--){
            for (int u = 1; u <= a + b && j + u <= k;u++){
                int x, y;
                if(u<=b-a){
                    x = a;
                    y = b - u;
                }
                else{
                    x = (a + b - u) / 2;
                    y = a + b - u - x;
                }
                int res = dp[j] + a * b - x * y;
                dp[j + u] = min(dp[j + u], res);
            }
        }
    }
    int res = dp[k];
    if(res==inf)
        cout << -1 << endl;
    else
        cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
