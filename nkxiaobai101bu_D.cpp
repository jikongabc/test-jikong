#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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
const int N = 1e3 + 10;
int n, q;
int a[N];
LL pre[N];
int res[N];
int ans[N];

LL mysqrt(LL x){
    LL l = 0, r = x;
    while(l<r){
        LL mid = l + r + 1 >> 1;
        if(mid*mid<=x)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n;i++){
        for (int j = i; j <= n;j++){
            LL t = pre[j] - pre[i - 1];
            LL tt = mysqrt(t);
            if(tt*tt==t)
                res[i]++, res[j + 1]--;
        }
    }
    for (int i = 1; i <= n;i++)
        ans[i] = ans[i - 1] + res[i];
    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}