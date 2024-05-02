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
const int N = 505;
int num1, num2;
int n, m;
int p, q;
int T;
int a[N];
int t[N], w[N];
int dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> num1 >> num2 >> n >> m;
    for (int i = 1; i <= m;i++){
        cin >> a[i];
        a[i] *= (num2 / num1);
    }
    for (int i = 1; i <= n;i++){
        int p, q;
        cin >> p >> q;
        t[i] = a[p], w[i] = q;
    }
    cin >> T;
    for (int i = 1; i <= n;i++){
        for (int j = T; j >= t[i];j--){
            dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
        }
    }
    cout << dp[T];
    return 0;
}