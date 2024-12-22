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
#include <bitset>
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);

void solve() {
    LL n, a, b, c;
    cin >> n >> a >> b >> c;
    LL dis = a + b + c;  
    LL m = n / dis;
    LL t = m * dis;
    LL cnt = m * 3;
    if (t < n) {
        cnt++;
        t += a;
        if (t >= n) {
            cout << cnt << endl;
            return;
        }
        cnt++;
        t += b;
        if (t >= n) {
            cout << cnt << endl;
            return;
        }
        cnt++;
        t += c;
        if (t >= n) {
            cout << cnt << endl;
            return;
        }
    }
    else {
        cout << cnt << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
