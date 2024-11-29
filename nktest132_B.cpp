#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    LL res = min(m, k + 1);
    LL l = 0, need = 0;
    
    for (LL r = 0; r < a.size(); r++) {
        if (r > 0) {
            need += max(0LL, a[r] - a[r-1] - 1);
        }
        
        while (need > k) {
            if (r > 0) need -= max(0LL, a[l+1] - a[l] - 1);
            l++;
        }
        
        res = max(res, a[r] - a[l] + 1 + min(k - need, (a[l] > 1 ? a[l] - 1 : 0) + (a[r] < m ? m - a[r] : 0)));
    }

    cout << res << endl;
    return 0;
}