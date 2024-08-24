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
#define int long long
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n;
int a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    LL res = 0;
    cin>>n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        int t = (res % 3 == 0) ? 0 : (3 - res % 3);
        res += t;
        if(t==1)
            a[i] -= 3;
        else if(t==2)
            a[i] -= 4;
        if(a[i]<=0)
            continue;
        res += (a[i] / 5);
        a[i] = (a[i] % 5);
        if(a[i]>2)
            res += 3;
        else
            res += a[i];
    }
    cout << res << endl;
    // for (int i = 0; i < n;i++)
    //     cout << a[i] << ' ';
        return 0;
}
