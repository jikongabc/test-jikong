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
const int N = 2e5 + 10;
int a[N];
int pre[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    pre[0] = a[0];
    for (int i = 1; i < n;i++){
        pre[i] = max(pre[i - 1], a[i]);
    }
    int res = 0;
    for (int i = 1; i < n;i++){
        int t = ~(a[i] ^ pre[i-1]) & ((1 << m) - 1);
        res = max(res, t);
    }
        cout << res << endl;
    return 0;
}
