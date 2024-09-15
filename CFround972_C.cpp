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
const int N = 1e5 + 10;
string s = "aeiou";
int n, m, q;
int b[N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);
    while (q--)
    {
        int x;
        cin >> x;
        int x1 = 0, x2 = inf;
        int t = lower_bound(b, b + m, x) - b;
        // cout << t;
        // if(b[t]==x){
        //     cout << 0 << endl;
        //     continue;
        // }
        if(t==m){
            cout << n - b[m - 1] << endl;
        }
        else if(t==0){
            cout << b[0] - 1 << endl;
            continue;
        }
        else{
            cout << (b[t] - b[t - 1]) / 2 << endl;
        }
        // x2 = b[t], x1 = b[t - 1];
        // if (x > x1 && x < x2)
        // {
        //     int t = (x1 + x2) / 2;
        //     cout << min(abs(x1 - t), abs(x2 - t)) << endl;
        // }
        // else if (x < x1 && x >= 1)
        // {
        //     cout << x1 - 1 << endl;
        // }
        // else if (x > x2 && x <= n)
        //     cout << n - x2 << endl;
    }
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