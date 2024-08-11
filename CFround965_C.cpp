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
typedef pair<LL, LL> PLL;
const int N = 2e5 + 10;
PLL a[N];
int n, k;

bool check(LL mid){
    int cnt = 0;
    vector<int> v;
    for (int i = 0; i < n - 1; i++){
        if(a[i].first>=mid)
            cnt++;
        else if(a[i].second==1){
            v.push_back(mid - a[i].first);
        }
    }
    reverse(v.begin(), v.end());
    int t = k;
    for(auto i:v){
        if(t>=i){
            t -= i;
            cnt++;
        }
    }
    return cnt >= (n + 1) / 2;
}

void solve(){
    LL res = 0;
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> a[i].first;
    }
    for (int i = 0; i < n;i++){
        cin >> a[i].second;
    }
    sort(a, a + n);
    //加最大的数
    for (int i = 0; i < n;i++){
        if(a[i].second==1){
            LL med;
            if (i < n / 2)
                med = a[n / 2].first;
            else
                med = a[(n - 2) / 2].first;
            res = max(res, a[i].first + k + med);
        }
    }   
    //加中位数
    LL l = 0, r = 2e9;
    while(l<r){
        LL mid = l + r + 1 >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    res = max(res, a[n - 1].first + l);
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
