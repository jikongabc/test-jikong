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
const int N = 100000;  
LL a[N];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    LL n;
    cin >> n;
    LL minn = LLONG_MAX;
    LL maxn = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < minn) minn = a[i];
        if (a[i] > maxn) maxn = a[i];
    }

    LL t = (minn + maxn + 1) / 2;

    LL s1 = 0;
    LL s2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < t) {
            s1 = max(s1, t - a[i]);
        } else if (a[i] > t) {
            s2 = max(s2, a[i] - t);
        }
    }

    LL res = max(2 * s1 - 1, 2 * s2);
    if (res < 0) res = 0;

    cout << res << ' ' << t;

    return 0;
}