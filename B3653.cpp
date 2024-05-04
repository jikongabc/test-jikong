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
const int N = 1e6 + 10;
int n;
int dp[N] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 5, 2, 1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 12; i <= n;i++){
        dp[i] = min({dp[i - 1], dp[i - 5], dp[i - 11]}) + 1;
    }
    cout << dp[n];
    return 0;
}