#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
int T, M, t[N], w[N];
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> M;
    for (int i = 1; i <= M;i++){
        // cin >> t[i] >> w[i];
        int t, w;
        cin >> t >> w;
        for (int j = T; j >= t; j--){
            dp[j] = max(dp[j], dp[j - t] + w);
        }
    }
    // for (int i = 1; i <= M;i++){
    //     for (int j = T; j >=t[i] ;j--){
    //         dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
    //     }
    // }
    cout << dp[T];

    return 0;
}