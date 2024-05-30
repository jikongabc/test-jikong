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
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
LL n;
LL m;
const int N = 1e5 + 10;
LL s[N];
LL v[N];

bool check(LL t){
    LL sum = 0;
    LL maxn = 0;
    for (int i = 0; i < n;i++){
        if(t<s[i])
            continue;
        sum += v[i] * (t - s[i]);
        maxn = max(maxn, v[i] * (t - s[i]));
    }
    return sum - maxn >= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> s[i] >> v[i];
    }
    LL l = 1, r = 5e9;
    LL ans = -1;
    while(l<=r){
        LL mid = (l + r) >> 1;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}