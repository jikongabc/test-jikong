#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n;
int a[N];
LL pre2[N];

void solve(){
    cin >> n;
    LL sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    memset(pre2, 0, sizeof pre2);
    for(int i = n; i > 0; i--){
        pre2[i] = pre2[i + 1] + a[i];
    }
    LL maxn = 0;
    for(int i = 1; i <= n; i++){
        LL t = (LL)i * i + pre2[i + 1];
        maxn = max(maxn, t);
    }
    maxn = max(maxn, sum);
    cout << maxn << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
