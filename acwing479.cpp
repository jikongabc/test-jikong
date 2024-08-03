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
const int N = 35;
int n;
int dp[N][N];
int res[N][N];
int w[N];

void dfs(int l,int r){
    if(l>r)
        return;
    int t = res[l][r];
    cout << t << ' ';
    dfs(l, t - 1);
    dfs(t + 1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> w[i];
    }
    for (int len = 1; len <= n;len++){
        for (int i = 1; i + len - 1 <= n;i++){
            int j = i + len - 1;
            if(len==1){
                dp[i][j] = w[i];
                res[i][j] = i;
            }
            else{
                for (int k = i; k <= j;k++){
                    int left = k == i ? 1 : dp[i][k - 1];
                    int right = k == j ? 1 : dp[k + 1][j];
                    int score = left * right + w[k];
                    if (dp[i][j] < score){
                        dp[i][j] = score;
                        res[i][j] = k;
                    }
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    dfs(1, n);
    return 0;
}