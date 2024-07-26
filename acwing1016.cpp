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
typedef pair<int, PII> PIII;
const int N = 1010;
int n;
int a[N];
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        dp[i] = a[i];
        for (int j = 1; j < i;j++){
            if(a[j]<a[i])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}