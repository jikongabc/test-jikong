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
const int N = 1e5 + 10;
int n, m;
int a[N], b[N], k[N];

// bool check(int x,int i){
//     auto l = lower_bound(a, a + n, b[i] - x);
//     auto r = upper_bound(a, a + n, b[i] + x);
//     return r - l >= k[i];
// }
bool check(int x,int i){
    auto l = lower_bound(a, a + n, b[i] - x);
    auto r = upper_bound(a, a + n, b[i] + x);
    return *r - *l >= k[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m;i++){
        cin >> b[i] >> k[i];
        int l = 0, r = 2e8;
        while(l<r){
            int mid = l + r >> 1;
            if(check(mid,i))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
        return 0;
}