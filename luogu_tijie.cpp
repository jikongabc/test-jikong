#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
int m, n;
int a[N], b[N];
int main(){
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + m + 1);
    LL res = 0;
    for (int i = 1; i <= n; i++){
        LL l = 0, r = n + 1;
        while(l<r){
            LL mid = l + r >> 1;
            if(a[mid]<=b[i])
                l = mid + 1;
            else
                r = mid;
        }
        if(b[i]<=a[1])
            res += a[1] - b[i];
        else
            res += min(abs(a[l - 1] - b[i]), abs(a[l] - b[i]));
    }
    cout << res;
    return 0;
}


