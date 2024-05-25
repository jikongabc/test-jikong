// #include<iostream>
// #include<sstream>
// #include<algorithm>
// #include<cstring>
// #include<string>
// #include<vector>
// #include<queue>
// #include<deque>
// #include<map>
// #include<set>
// #include<unordered_map>
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// const int N = 2e5 + 10;
// int n;
// int a[N], b[N];
// bool st[N];
// bool flag;

// int gcd(int a,int b){
//     return b ? gcd(b, a % b) : a;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n;i++){
//         cin >> a[i];
//         if(i>=2 && a[i-1] % a[i] )
//             flag = 1;
//     }
//     if(flag){
//         cout << -1;
//         return 0;
//     }
//     for (int i = 1; i <= n;i++){
//         if(a[i]!=a[i-1])
//             b[i] = a[i];
//         else{
//             for (int j = b[i - 1]; j <= n;j+=a[i]){
//                 if(!st[j] && gcd(a[i-1],j)==a[i]){
//                     b[i] = j;
//                     break;
//                 }
//             }
//         }
//         if(!b[i]){
//             cout << -1;
//             return 0;
//         }
//         st[b[i]] = 1;
//     }
//     for (int i = 1; i <= n;i++){
//         cout << b[i] << ' ';
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 2e3 + 10;
int n, k;
int v[N], w[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> v[i] >> w[i];
    }
    int ans = 0;
    for (int i = 0; i <= 2010;i++){
        int res = (1 << 20) - 1;
        for (int j = 1; j <= n;j++){
            if((w[j]&i)==i)
                res &= v[j];
        }
        if(res<=k)
            ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
