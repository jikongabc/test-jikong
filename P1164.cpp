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
const int N = 305, M = 10010;
int n, m;
int dp[M];
int a[N];
//  dp[i][j]  前i个菜恰好花掉j元的方案数
//  dp[i][j]+=dp[i-1][j]
//  dp[i][j]+=dp[i-1][j-a[i]]
//  dp[i][0]=1
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n;i++)
        dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = m; j >=a[i];j--){
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m];
    return 0;
}
