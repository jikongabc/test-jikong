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
const int N = 205, M = 10001;
int n, m;
int K;
int b[M];
int dp[M];
int flag[N][N];
int g[M], w[M];
int x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n;i++){
        cin >> g[i] >> w[i] >> x;
        K = max(K, x);
        b[x]++;
        flag[x][b[x]] = i;
    }
    for (int i = 1; i <= K;i++){
        for (int j = m; j >= 0;j--){
            for (int k = 1; k <= b[i];k++){
                if(j>=g[flag[i][k]]){
                    dp[j] = max(dp[j], dp[j - g[flag[i][k]]] + w[flag[i][k]]);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}