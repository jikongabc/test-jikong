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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
string s;
int pre[N];

void solve(){
    cin >> s;
    int n = s.size();
    for (int i = 1; i <= n;i++){
        pre[i] = pre[i - 1] + ((s[i - 1] == '1') ? 1 : -1);
    }
    map<int, int> ma;
    ma[0] = 1;
    int res = 0;
    for (int i = 1; i <= n;i++){
        res = (res + (ma[pre[i]] ) * (n - i + 1)) % mod;
        ma[pre[i]] += (i+1);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}