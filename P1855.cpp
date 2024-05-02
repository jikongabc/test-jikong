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
const int N = 1005;
int n, m, t;
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n;i++){
        int a, b;
        cin >> a >> b;
        for (int j = m; j >= a;j--){
            for (int k = t; k >= b;k--){
                dp[j][k] = max(dp[j][k], dp[j - a][k - b] + 1);
            }
        }
    }
    cout << dp[m][t];
    return 0;
}