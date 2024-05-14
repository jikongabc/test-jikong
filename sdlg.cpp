// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// typedef pair<double, int> PDI;
// const int N = 5005;
// int a[N];
// int dp[N];
// int n, m;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         dp[i] = 1;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (a[j] >= a[i])
//                 dp[i] = max(dp[i], dp[j] + 1);
//             else
//                 dp[i] = max(dp[i], dp[j]);
//         }
//     }
//     // for (int i = 0; i < n;i++){
//     //     cout << dp[i] << ' ';
//     // }
//     int maxn = 0;
//     for (int i = 0; i < n; i++)
//     {
//         maxn = max(maxn, dp[i]);
//     }
//     if (maxn > m)
//         cout << "Karashi lovelove";
//     else
//         cout << "Karashi cblcd";
//     return 0;
// }

#include <iostream>
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
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 200;
int n, q;
string s;
int cnt[N];

bool check(string s){
    for (int i = 0; i < s.size();i++){
        if(cnt[s[i]]!=1)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    cin >> s;
    while(q--){
        memset(cnt, 0, sizeof cnt);
        string x;
        cin >> x;
        int len = x.size();
        int maxn = 0;
        int l = 0, r = 0;
        while(r<n){
            cnt[s[r]]++;
            r++;
            if(check(x))
                maxn = max(maxn, r - l);
            for(auto c:x) 
                while(cnt[c]>1){
                    cnt[s[l]]--;
                    l++;
                }
        }
        cout << maxn << endl;
    }

    return 0;
}
