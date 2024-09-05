#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

void test()
{
    LL n, k;
    cin >> n >> k;
    LL sum = 0;
    for (int i = k; i <=  k + n - 1 ;i++){
        sum += i;
    }
    LL sum1 = 0;
    LL res = 1e18;
    LL vis;
    for (int i = k; i <=  k + n - 1 ;i++){
        sum1 += i;
        if(abs(sum1-(sum-sum1)<res)){
            res = abs(sum1 - (sum - sum1));
            vis = i;
        } 
    }
    LL sum2 = 0;
    for (int i = k + n - 1; i >= k;i--){
        sum2 += i;
        // cout << i << "-->" << sum2 - (sum - sum2) << endl;
    }
    cout << endl;
    cout << vis << "-->" << res << endl;
    // cout << "sum:" << sum << endl;
}

void solve(){
    LL n, k;
    cin >> n >> k;
    LL sum = (k + k + n - 1) * n / 2;
    // // cout << "sum:"<< sum << endl;
    // LL sum1 = 0;
    // bool flag = false;
    // for (LL i = k + n - 1; i >= k;i--){
    //     sum1 += i;
    //     // cout << i << "-->" << sum1 - (sum - sum1) << ' ' << (sum1 + i - 1) - (sum - (sum1 + i - 1)) << endl;
    //     if ((sum1 - (sum - sum1) < 0) && ((sum1 + i - 1) - (sum - (sum1 + i - 1)) > 0) && i > k){
    //         cout << min(abs(sum1 - (sum - sum1)), abs((sum1 + i - 1) - (sum - (sum1 + i - 1)))) << endl;
    //         flag = true;
    //         break;
    //     }
    // }
    // if(!flag)
    //     cout << k + n - 1 - (sum - k - n + 1) << endl;
    LL l = 0, r = n;
    while(l<r){
        LL mid = l + r + 1 >> 1;
        LL sum1 = mid * (k + k + mid - 1) / 2;
        if(sum1<=sum-sum1)
            l = mid;
        else
            r = mid - 1;
    }
    // cout << r << endl;
    if(r==n)
        cout << k + n - 1 - (sum - k - n + 1) << endl;
    else{
        LL a = abs(r * (k + k + r - 1) / 2 - (sum - (r * (k + k + r - 1) / 2)));
        r++;
        LL b = abs(r * (k + k + r - 1) / 2 - (sum - (r * (k + k + r - 1) / 2)));
        cout << min(a, b) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        // test();
        solve();
    }
    return 0;
}