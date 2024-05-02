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
const int N = 30005;
int n, m;
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int w, v;
        cin >> v >> w;
        w *= v;
        for (int j = n; j >= v;j--){
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[n];
    return 0;
}