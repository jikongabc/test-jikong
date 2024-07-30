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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 105;
int n;
int a[N];
bool dp[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int res = 0;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int m = a[n];
        memset(dp, false, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n;i++){
            if(!dp[a[i]])
                res++;
            for (int j = a[i]; j <= m;j++){
                dp[j] |= dp[j - a[i]];
            }
        }
        cout << res << endl;
    }
    return 0;
}