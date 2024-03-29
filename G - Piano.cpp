// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <set>
// #include <map>
// #include <vector>
// #include <unordered_map>
// #include <string>
// using namespace std;
// using LL = long long;
// const int N = 2e6 + 10;
// unordered_map<int, LL> ma;
// set<char> se;
// string s;
// // struct node{
// //     char ch;
// //     int count;
// // } p[N];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> s;
//     for (int i = 0; i < 26;i++){
//         ma[i] = 0;
//     }
//     for (int i = 0; i < s.size(); i++)
//     {
//         ma[s[i] - 'a']++;
//         se.insert(s[i]);
//     }
//     LL size = se.size();
//     // LL ans = (size * (size - 1) / 2);
//     LL ans = 0;
//     for (int i = 0; i < 26;i++){
//         for (int j = i+1; j < 26;j++){
//             ans += ma[i] * ma[j];
//         }
//     }
//     int temp = 0;
//     for (int i = 0; i < 26;i++){
//         if(ma[i]>1)
//             temp++;
//     }
//     if(temp)
//         ans++;
//         // for (int i = 0; i < 26;i++){
//         //     if(ma[i]>1)
//         //         ans += (ma[i] - 1) * (s.size() - ma[i]);
//         // }
//         // if(size==1)
//         //     cout << 1;
//         // else if(s.size()==2 && size==2)
//         //     cout << 2;
//         // else
//             // cout << ans;
//         cout<<ans;
//         return 0;
// }

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
const int inf = 9999999;
const int mod = 1e9 + 7;
char a[N];
long long l, bz[N];
long long n, ans;
signed main()
{
    scanf("%s", a + 1);
    l = strlen(a + 1);
    for (int i = 1; i <= l; i++)
    {
        bz[a[i] - 'a' + 1]++;
    }
    for (int i = 1; i <= 26; i++)
    {
        for (int j = i + 1; j <= 26; j++)
        {
            ans += bz[i] * bz[j];
        }
    }
    int ss = 0;
    for (int i = 1; i <= 26; i++)
    {
        if (bz[i] > 1)
            ss++;
    }
    if (ss != 0)
        ans++;
    cout << ans;
}