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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 85, M = 1e4 + 10;
int n;
int x, y;
int a[N], b[N];
int dp[N][N][M];
int res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i <= n;i++){
        cin >> a[i] >> b[i];
    }
    memset(dp, inf, sizeof dp);
    dp[0][0][0] = 0;
    //从前i道菜中选j道菜，总甜度为k
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < i;j++){
            for (int k =0; k <= x;k++){
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                if(j > 0 && k>=a[i])
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - a[i]] + b[i]);
            }
        }
    }
    for (int i = n; i >= 0;i--){
        for (int j = 0; j <= x;j++){
            if(dp[n][i][j]<=y){
                cout << i+1 << endl;
                return 0;
            }
                
        }
    }
    return 0;
}