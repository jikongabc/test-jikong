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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int x[N], y[N];
bool vis[N][2];
int cnt[N];
int n;

void solve()
{
    LL res = 0;
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        vis[x[i]][y[i]] = 1;
        cnt[y[i]]++;
    }
    for (int i = 0; i < n;i++){
        if(vis[x[i]][1-y[i]])
            res += cnt[y[i]] - 1;
        if(x[i]>0 && x[i]<n && vis[x[i]-1][1-y[i]] && vis[x[i]+1][1-y[i]])
            res++;
    }
    cout << res << endl;
}

int main()
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