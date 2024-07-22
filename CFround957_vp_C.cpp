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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e5 + 10;
int n, m, k;
int a[N];
int f[N];
int g[N];
int sum_f[N];
int sum_g[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int res = 0;
        int ans[N];
        cin >> n >> m >> k;
        int l = 1, r = n;
        for (int i = n; i >=1;i--){
            if(i>=k || i>m)
                a[l++] = i;
            else
                a[r--] = i;
        }
        for (int i = 1; i <= n;i++){
            cout << a[i] << ' ';
        }
        cout << endl;
        // cout << res << endl;
    }
    return 0;
}