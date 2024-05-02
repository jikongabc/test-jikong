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
const int N = 50010;
int n, m;
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n;i++){
        int a;
        cin >> a;
        for (int j = m; j >= a;j--){
            dp[j] = max(dp[j], dp[j - a] + a);
        }
    }
    cout << dp[m];
    return 0;
}