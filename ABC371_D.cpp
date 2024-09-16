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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 2e5 + 10;
int n;
int x[N];
int a[N];
LL pre[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> x[i];
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int _r = upper_bound(x + 1, x + 1 + n, r) - x;
        int _l = lower_bound(x + 1, x + 1 + n, l) - x;
        cout << pre[_r-1] - pre[_l - 1] << endl;
    }
    return 0;
}