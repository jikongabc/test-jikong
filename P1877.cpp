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
const int N = 2005;
int n, bg, m;
int a[N];
bool dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> bg >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    dp[0][bg] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m; j++){
            if(dp[i-1][j] && j+a[i]<=m)
                dp[i][j + a[i]] = 1;
            if(dp[i-1][j] && j-a[i]>=0)
                dp[i][j - a[i]] = 1;
        }
    }
    for (int i = m; i >= 0;i--){
        if(dp[n][i]){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}