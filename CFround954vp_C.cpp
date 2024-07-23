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
const int N = 2e5 + 10;
int n, m;
string s;
string ss;
int a[N];

void solve(){
    bool st[N] = {0};
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= m;i++)
        cin >> a[i];
    cin >> ss;
    sort(ss.begin(), ss.end());
    sort(a + 1, a + 1 + m);
    int cnt = 0;
    for (int i = 1; i <= m;i++){
        if(!st[a[i]-1]){
            s[a[i] - 1] = ss[cnt++];
            st[a[i] - 1] = 1;
        }
        // cout << a[i] - 1 << ' ' << i - 1 << endl;
    }
    cout << s << endl;
    // cout << ss << endl;
}

int main()
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