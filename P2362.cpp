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
const int N = 105;
int n;
int a[N];
int cnt[N];
int dp[N];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        int flag;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            dp[i] = 1;
            cnt[i] = 1;
        }
        for (int i = 1; i <= n;i++){
            for (int j = 1; j < i;j++){
                if(a[i]>=a[j])
                    // dp[i] = max(dp[i], dp[j] + 1);
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i]==dp[j]+1)
                        cnt[i] += cnt[j];
            }
        }
        // for (int i = 1; i <= n;i++)
        //     cout << dp[i] << ' ';
        // cout << endl;
        for (int i = 1; i <= n; i++){
            if(dp[i]>ans){
                ans = dp[i];
                flag = i;
            }
        }
        cout << ans << ' ' << cnt[flag] << '\n';
    }

    return 0;
}