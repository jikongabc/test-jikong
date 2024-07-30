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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1010;
int n, m;
int v[N], w[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = n; i >= 1;i--){
        for (int j = 0; j <= m;j++){
            dp[i][j] = dp[i + 1][j];
            if(j>=v[i])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    int j = m;
    for (int i = 1; i <= n;i++){
        if(j>=v[i] && dp[i][j]==dp[i+1][j-v[i]]+w[i]){
            cout << i << ' ';
            j -= v[i];
        }
    }
        return 0;
}