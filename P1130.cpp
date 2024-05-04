#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 2005;
int n, m;
int a[N][N];
int dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> a[i][j];
        }
    }
    int temp;
    memset(dp, inf, sizeof dp);
    for (int i = 0; i < n;i++)
        dp[0][i] = a[i][0];
    for (int i = 1; i < m;i++){
        for (int j = 0; j < n;j++){
            if(j==0)
                temp = n-1;
            else
                temp = j - 1;
            dp[i][j] = min(dp[i - 1][j] + a[j][i], dp[i - 1][temp] + a[j][i]);
        }
    }
    // for (int i = 0; i < m;i++){
    //     for (int j = 0; j < n;j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = inf;
    for (int i = 0; i < n;i++){
        ans = min(ans, dp[m-1][i]);
    }
    cout << ans;
    return 0;
}

//dp[i][j] i天  j组
//dp[i][j]=max dp[i-1][k] k=0,1,..,n-1+a[i][j]
