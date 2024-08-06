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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
int f[N];

void init(){
    f[0] = 0;
    for (int i = 1; i < N;i++)
        f[i] = f[i / 3] + 1;
}

void solve(){
    int l, r;
    cin >> l >> r;
    LL res = 0;
    res += 2 * f[l];
    for (int i = l + 1; i <= r;i++)
        res += f[i];
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
