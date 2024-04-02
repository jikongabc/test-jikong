#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
LL n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    LL l = 1, r = 2e9;
    LL ans;
    while(l<=r){
        LL mid = (l + r) >> 1;
        if((LL)mid*log10(mid*1.0)+1<n){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}