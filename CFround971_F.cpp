#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
int q;
int l, r;
vector<LL> pre(N);
//1 2 3 4  2 3 4 1  3 4 1 2   4 1 2 3 

LL sum(LL x){
    LL res = 0;
    int u = x / n;
    res += u * pre[n];
    int v = x % n;
    if(v){
        if(u+v<=n)
            res += pre[u + v] - pre[u];
        else
            res += pre[u + v - n] - pre[u] + pre[n];
    }
    return res;
}

void solve()
{
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    
    while(q--){
        cin >> l >> r;
        cout << sum(r) - sum(l - 1) << endl;
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}