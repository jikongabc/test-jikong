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
const int N = 1e5 + 10;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    for (int i = 1; i <= k / 2;i++){
        cout << x + i << ' ' << y << endl;
        cout << x - i << ' ' << y << endl;
    }
    if (k & 1)
        cout << x << ' ' << y << endl;
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
