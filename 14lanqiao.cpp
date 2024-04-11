// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<vector>
// #include<map>
// #include<set>
// #include<queue>
// #include<deque>
// #include<unordered_map>
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// // const int N = 20;
// // int n;

// // struct node{
// //     int t, d, l;
// // } p[N];

// // bool st[N];

// // bool dfs(int x,int end1){
// //     if(x==n)
// //         return true;
// //     for (int i = 0; i < n;i++){
// //         if(!st[i] && p[i].t+p[i].d>=end1){
// //             st[i] = true;
// //             if(dfs(x+1,max(end1,p[i].t)+p[i].l))
// //                 return true;
// //             st[i] = false;
// //         }
// //     }
// //     return false;
// // }

// // int main(){
// //     ios::sync_with_stdio(0);
// //     cin.tie(0);
// //     cout.tie(0);
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         cin >> n;
// //         for (int i = 0; i < n;i++){
// //             cin >> p[i].t >> p[i].d >> p[i].l;
// //         }
// //         memset(st, false, sizeof st);
// //         if(dfs(0, 0))
// //             cout << "YES\n";
// //         else
// //             cout << "NO\n";
// //     }
// //     return 0;
// // }

// #include <iostream>
// #include <cstring>
// #include <string>
// using namespace std;
// typedef long long LL;
// const int N = 1e5 + 10;
// string s[N];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         cin >> s[i];
//     }
//     int ans = 0;
//     int j;
//     for (int i = 1; i <n;i=j){
//          j = i + 1;
//         while (s[i][s[i].size() - 1] != s[j][0]){
//             j++;
//         }
//         ans += j - i - 1;
//         // i = j;
//     }
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <string>
// using namespace std;
// typedef long long LL;
// const int N = 5e5 + 10;
// int k;
// string s;
// char a, b;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> k;
//     int ans = 0;
//     cin >> s >> a >> b;
//     for (int i = 0; i <= s.size() - k; i++){
//         if (s[i] == a){
//             for (int j = i + k - 1; j < s.size(); j++){
//                 if (s[j] == b)
//                     ans++;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }



#include<iostream>
#include<cstring>
#include<string>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
string s;
int k;
char a, b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    cin >> s;
    cin >> a >> b;
    LL size = s.size();
    LL cnt = 0, ans = 0;
    for (int i = size - k, j = size - 1; i >= 0;i--,j--){
        if(s[j]==b)
            cnt++;
        if(s[i]==a)
            ans += cnt;
    }
    cout << ans;
    return 0;
}