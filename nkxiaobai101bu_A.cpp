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
const int N = 1e6 + 10;
int n, k;
int a[N];
LL pre[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    LL res = 0;
    for (int i = 1; i <= n;i++){
        LL t = pre[i + n - k - 1] - pre[i - 1];
        res = max(res, t);
    }
    cout << res;
    return 0;
}