#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
typedef pair<double, int> PDI;
const int N = 1010;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
char s[N];
char s1[N];
int n;
int dp[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s + 1;
    n = strlen(s+1);
    for (int i = 1; i <= n;i++){
        s1[i] = s[n-i+1];
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(s[i]==s1[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[n][n];
    // cout << s1+1;

    return 0;
}