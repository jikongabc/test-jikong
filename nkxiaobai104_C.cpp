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
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int n;
vector<LL> a;

bool check(LL k) {
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        LL t = max(a[i] - k, 0LL);
        sum += t;
    }
    return sum <= (LL)(3 * k);
}

int main() {
    cin >> n;
    a.resize(n);
    LL maxn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maxn)
            maxn = a[i];
    }

    LL l = 0, r = 1e18;
    while (l < r) {
        LL mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;  
    return 0;
}
