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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
const int mod = 998244353;
int n;
int a[N];
int cnt[1000005];
int f[1000005];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i <= 1000000;i++){
        if(i==0)
            f[i] = 1;
        else
            f[i] = (f[i - 1] * i) % mod;
    }
    sort(a, a + n);
    int res = 0;
    int ans = 2;
    for (int i = 0; i < n;i++){
        for (int j = i; j < n;j++){
            res += a[j] - a[i];
        }
    }
    for (int i = 0; i <= 1000000;i++){
        ans = (ans * f[cnt[i]]) % mod;
    }
    if(n==1)
        ans = 1;
    if(a[0]==a[n-1]){
        ans = f[n];
    }
    cout << res << ' ' << ans << endl;
    return 0;
}