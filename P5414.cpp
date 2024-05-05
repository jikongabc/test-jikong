#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 110;
int n;
int a[N];
int dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int sum = 0;
        int res = -inf;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            sum += a[i];
            dp[i] = a[i];
        }
        for (int i = 1; i <= n;i++){
            for (int j = 1; j < i;j++){
                if (a[i] >= a[j])
                    dp[i] = max(dp[i], dp[j] + a[i]);
            }
                // cout << dp[i] << ' ';
            res = max(res, dp[i]);
        }
        cout << sum - res << '\n';
    }
    return 0;
}

//if(a[i]>=a[i-1])
//dp[i]=max(dp[i],dp[i-1]+a[i])
