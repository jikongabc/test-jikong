#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;
using LL = long long;
const int N = 1e5+5;
LL n, k;
LL a[N];

LL connect(LL a,LL b){
    return stoll(to_string(a) + to_string(b));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a+1, a + n+1);
    LL ans = 0;
    for (int i = 1, j = n; i <= n; i++)
    {
        while(j>0 && connect(a[j],a[i])>k){
            j--;
        }
        ans += j;
        if(j>=i)
            ans -= 1;
    }
    // for (int i = 0, j = n - 1; i < n; i++)
    // {
    //     while (j>=0 && connect(a[i], a[j]) > k){
    //         j--;
    //     }
    //     ans += j - i + 1;
    // }
    cout << ans;
    return 0;
}