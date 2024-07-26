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
int n = 1;
int a[N];
int dp[N], q[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>a[n])
        n++;
    int res = 0, cnt = 0;
    for (int i = 1; i < n;i++){
        dp[i] = 1;
        for (int j = 1; j < i;j++){
            if(a[i]<=a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    for (int i = 1; i < n;i++){
        int k = 0;
        while(k<cnt && q[k]<a[i])
            k++;
        if(k==cnt)
            q[cnt++] = a[i];
        else
            q[k] = a[i];
    }
    cout << cnt << endl;
    return 0;
}