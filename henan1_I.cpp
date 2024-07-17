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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int a[N];
LL solve(int n, LL t)
{
    if(t>n)
        t = n;
    int maxn = *max_element(a, a + n);
    if(maxn==a[0])
        return 0;
    // int max_val = *max_element(a+n-t, a + n);
    // int max_pos = find(a+n-t, a + n, max_val) - a;
    maxn = 0;
    int max_pos;
    for (int i = n-t; i < n;i++){
        if(a[i]>=maxn){
            maxn = a[i];
            max_pos = i;
        }
    }
    int res = n - max_pos;
    return res % n;
}

signed main()
{
    int n;
    LL t;
    cin >> n >> t;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int res = solve(n, t);
    if (res == n)
        cout << 0;
    else
        cout << res;

    return 0;
}
