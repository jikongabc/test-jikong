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
int n, m, x;
int dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    for (int i = 1; i <= n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = x; j >= c;j--){
            for (int k = m; k >= b;k--){
                dp[j][k] = max(dp[j][k], dp[j - c][k - b] + a);
            }
        }
    }
    cout << dp[x][m];
    return 0;
}