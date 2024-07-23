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
int n, m;
int fa[N];
LL a[N];
int res;

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        int pu = find(u), pv = find(v);
        if (pu != pv)
        {
            fa[pu] = pv;
            a[pv] = max(a[pv], a[pu]);
        }
    }
    LL minn = inf;
    for (int i = 1; i <= n;i++){
        if(fa[i]==i){
            res += a[i];
            minn = min(minn, a[i]);
        }
    }
    res -= minn;
    cout << res;
    return 0;
}