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
const int N = 100010;
int n, m;
LL dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        int g, w;
        cin >> g >> w;
        for (int j = m; j >= g;j--){
            dp[j] = max(dp[j], dp[j - g] + w);
        }
    }
    cout << dp[m];
    return 0;
}
