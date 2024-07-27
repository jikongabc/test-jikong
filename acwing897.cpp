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
const int N = 1005;
int n, m;
char a[N];
char b[N];
int dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> a + 1 >> b + 1;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i]==b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m];
    return 0;
}