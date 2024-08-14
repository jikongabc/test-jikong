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
const int N = 1e6 + 10;
LL n;
LL a[N];

LL solve(LL l, LL r)
{
    LL sum = 0;
    LL up = 0, down = 0;

    for(int i=0;i<n;i++){
        if (a[i] < l){
            up += (l - a[i]);
        }
        else if (a[i] > r){
            down += (a[i] - r);
        }
    }
    if (up > down){
        return up;
    }
    else{
        return down;
    }
}

int main()
{
    cin >> n;
    LL maxn = 0, minn = 1e18;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    LL l, r;
    cin >> l >> r;
    if(l>=maxn || r<=minn){
        cout << -1;
        return 0;
    }
    LL res = solve(l, r);
    cout << res << endl;
    return 0;
}
