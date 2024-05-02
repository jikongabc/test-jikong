#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 505;
int H, T;
int n;
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> T >> n;
    for (int i = 1; i <= n;i++){
        int h, t, w;
        cin >> h >> t >> w;
        for (int j = H; j >= h;j--){
            for (int k = T; k >= t;k--){
                dp[j][k] = max(dp[j][k], dp[j - h][k - t] + w);
            }
        }
    }
    cout << dp[H][T];
    return 0;
}