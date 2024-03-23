// #include<iostream>
// #include <algorithm>
// #include<cmath>
// #include<cstring>
// #include<map>
// #include<set>
// #include<vector>
// #define int long long
// using namespace std;
// int n, m, k, t;
// int a[100000005];
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m >> k >> t;
//     for (int i = 0; i < n * m;i++){
//         cin >> a[i];
//     }
//     int sum = 0,temp=0;
//     sort(a,a+n*m);
//     for (int i = n * m - 1; i >= 0; i--)
//     {
//         if(t<=0)
//             break;
//         else{
//             sum += a[i];
//             temp += a[i];
//             if (temp >= k)
//                 t += temp / k;
//                 temp %= k;
//                 t--;
//         }

//     }
//     cout << sum;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <cstring>
// #include <map>
// #include <set>
// #include <vector>
// using namespace std;
// #define int long long

// // int cheng(int n){
// //     if(n==1)
// //         return 1;
// //     else
// //         return cheng(n - 1) * n;
// // }

// // void solve(){

// // }
// signed main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int num = n * (n - 1) * pow(26, n - 2);
//         cout <<num%998244353<< endl;
//     }
// }

// #include <iostream>
// using namespace std;

// const int MOD = 998244353;

// // 求解 x 的幂对 MOD 取模的结果
// int pow_mod(int x, int n)
// {
//     int res = 1;
//     while (n > 0)
//     {
//         if (n % 2 == 1)
//         {
//             res = (1LL * res * x) % MOD;
//         }
//         x = (1LL * x * x) % MOD;
//         n /= 2;
//     }
//     return res;
// }

// // 求解组合数 C(n, k) 对 MOD 取模的结果
// int comb_mod(int n, int k)
// {
//     if (k < 0 || k > n)
//     {
//         return 0;
//     }
//     if (k > n - k)
//     {
//         k = n - k;
//     }
//     int res = 1;
//     for (int i = 0; i < k; ++i)
//     {
//         res = (1LL * res * (n - i)) % MOD;
//         res = (1LL * res * pow_mod(i + 1, MOD - 2)) % MOD;
//     }
//     return res;
// }

// // 求解满足条件的字符串数量
// int countValidStrings(int n)
// {
//     if (n < 2)
//     {
//         return 0;
//     }
//     int result = (1LL * comb_mod(n, 2) * pow_mod(24, n - 2)) % MOD;
//     return result;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n;
//         cin >> n;
//         int validCount = countValidStrings(n);
//         cout << validCount << endl;
//     }
//     return 0;
// }



#include<iostream>
#include <algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
int  solve(){
    queue<PII> q;
    LL n, m;
    cin >> n >> m;
    q.push({1, 1});
    LL count = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 3;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=n && b<=m ){
                q.push({a, b});
                count++;
                if(a==n && b==m ){
                    if(!count%2){
                        auto k = q.front();
                        int c = k.first, d = k.second;
                        if(c==1 && d==2)
                            return 1;
                        else if(c==2 && d==1)
                            return 2;
                            else
                                return 3;
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans=solve();
        cout << ans << endl;
    }
}



