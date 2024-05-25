#include <iostream>
#include <sstream>
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
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1e5 + 10;
LL n, k, q;
LL a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for (LL i = 1; i <= k;i++){
            cin >> a[i];
        }
        for (LL i = 1; i <= k;i++){
            cin >> b[i];
        }
        while(q--)
        {
            LL d;
            cin >> d;
            LL v = lower_bound(a + 1, a + 1 + k, d) - a-1;
            if(a[v]==d){
                cout << b[v] << ' ';
                continue;
            }
            LL ans = b[v] + (d - a[v]) * 1.0 * (b[v + 1] - b[v]) / (a[v + 1] - a[v]);
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
    //=
}