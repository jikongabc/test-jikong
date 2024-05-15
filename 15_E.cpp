#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        cout << n * 6 << ' ' << 3 << endl;
        cout << n << ' ' << 2 * n << ' ' << 3 * n << endl;
    }
    return 0;
}