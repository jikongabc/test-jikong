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
const int N = 5005;
int n;
PII a[N];
int dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int j = 1; j < i;j++){
            if(a[i].second>a[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}