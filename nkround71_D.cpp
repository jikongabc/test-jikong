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
const int d[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
const double pi = acos(-1);
const int N = 1e5 + 10;
int n;
string s;
LL a[N];
LL pre[3][N];

void solve(){
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            pre[i][j + 1] = pre[i][j] + (s[j] - '0' != i ? a[j] : 0);
        }
    }
    LL res = lnf;
    for (int i = 0; i < 6; i++){
        int c1 = d[i][0], c2 = d[i][1], c3 = d[i][2];
        LL minn = pre[c1][0] - pre[c2][0];
        LL t = minn + pre[c2][0] + (pre[c3][n] - pre[c3][0]);
        res = min(res, t);
        for (int j = 1; j <= n; j++){
            LL t = pre[c1][j] - pre[c2][j];
            minn = min(minn, t);
            LL tmp = minn + pre[c2][j] + (pre[c3][n] - pre[c3][j]);
            res = min(res, tmp);
        }
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
