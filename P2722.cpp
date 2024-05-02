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
const int N = 10010;
int n, m;
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n;i++){
        int w, t;
        cin >> w >> t;
        for (int j = 1; j <=m ;j++){
            if(j>=t)
                dp[j] = max(dp[j], dp[j - t] + w);
        }
    }
    cout << dp[m];
    return 0;
}