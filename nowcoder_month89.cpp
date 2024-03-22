// #include<iostream>
// #include<algorithm>
// #define int long long
// using namespace std;
// signed main(){
//     int n, m;
//     int a[1000005];
//     int minn = 0x3f3f3f3f;
//     int maxn = 0;
//     cin >> n >> m;
//     for (int i = 0; i < n;i++){
//         cin >> a[i];
//         minn = min(minn, a[i]);
//         maxn = max(maxn, a[i]);
//     }
//     if(minn==1 && maxn==m)
//         cout << "No";
//         else
//             cout << "Yes";

//         return 0;
// }


#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N = 1e5 + 10;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    int a[N];//数组
    int b[N];//a前缀和
    int c[N];//b前缀和
    int d[N];//减数组
    int e[N];//d前缀和
    cin >> t;
    while(t--){
        int n,sum=0;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
            sum += a[i];
        }
        int temp = n;
        sort(a+1, a + n+1);
        if(a[1]>=0){
            cout << sum<< endl;
            continue;
        }
        for (int i = 1; i <= n;i++){
            b[i] = b[i - 1] + a[i];
            c[i] = c[i - 1] + b[i];
            d[i] = c[i - 1] + a[i];
            e[i] = e[i - 1] + d[i];
            if(c[i]+a[i+1]>0)
                temp = i;
        }
        cout <<( b[n] - b[temp] + (e[temp] * (n-temp)) )<< endl;
    }
    return 0;
}