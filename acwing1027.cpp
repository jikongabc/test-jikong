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
const int N = 15;
int n;
int w[N][N];
int dp[N][N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b, c;
    while(cin>>a>>b>>c,a||b||c)
        w[a][b] = c;
    for (int k = 2; k <= n + n;k++){
        for (int i1 = 1; i1 <= n;i1++){
            for (int i2 = 1; i2 <= n;i2++){
                int j1 = k - i1, j2 = k - i2;
                if(j1>=1 && j1<=n && j2>=1 && j2<=n){
                    int t = w[i1][j1];
                    if(i1!=i2)
                        t += w[i2][j2];
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2 - 1] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1 - 1][i2] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2 - 1] + t);
                    dp[k][i1][i2] = max(dp[k][i1][i2], dp[k - 1][i1][i2] + t);
                }
            }
        }
    }
    cout << dp[n + n][n][n];
    return 0;
}