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
const int N = 405;
int n;
int a[N];
int s[N];
int dp1[N][N];//最小值
int dp2[N][N];//最大值

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= 2 * n;i++)
        s[i] = s[i - 1] + a[i];
    memset(dp1, 0x3f, sizeof dp1);
    memset(dp2, -0x3f, sizeof dp2);
    for (int len = 1; len <= n;len++){
        for (int i = 1; i + len - 1 <= 2 * n;i++){
            int j = i + len - 1;
            if(i==j){
                dp1[i][j] = dp2[i][j] = 0;
            }
            else 
            for (int k = i; k < j; k++){
                dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + s[j] - s[i - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    int minn = inf, maxn = -inf;
    for (int i = 1; i <= n; i++){
        minn = min(minn, dp1[i][i + n - 1]);
        maxn = max(maxn, dp2[i][i + n - 1]);
    }
    cout << minn << endl;
    cout << maxn << endl;
    return 0;
}