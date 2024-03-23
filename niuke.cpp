#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
// void solve(){
//     int n;
//     int a[500005];
//     cin >> n;
//     for (int i = 0; i < n;i++){
//         cin >> a[i];
//     }
//     sort(a, a + n);
//     int sum = 0;
//     for (int i = 0; i < n;i++){
//         a[i] += sum;
//         if(a[i]<0){
//             sum += a[i];
//         }
//         else if(i !=n-1)
//             a[n - 1] += a[i];
//     }
//     cout << a[n - 1]<<'\n';
// }
int n;
int a[500005];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        // solve();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] += sum;
            if (a[i] < 0)
            {
                sum += a[i];
            }
            else if (i != n - 1)
                a[n - 1] += a[i];
        }
        cout << a[n - 1] << '\n';
    }
    return 0;
}