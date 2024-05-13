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
// const int N = 1e5+10;
// int n;
// vector<LL> a, b;


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 0; i < n;i++){
//         int t;
//         cin >> t;
//         a.push_back(t);
//     }
//     if(n==1){
//         cout << a[0];
//         return 0;
//     }
//     sort(a.begin(), a.end());
//     if (n == 2){
//         cout << a[1] * a[0];
//         return 0;
//     }
//     // for (auto i : a)
//     // {
//     //     cout << i << ' ';
//     // }
//     // cout << endl;
//     auto l = a.begin(), r = --a.end();
//     if(n%2!=0){
//         b.push_back(*r);
//         r--;

//     }    
//     while(l<r){
//         b.push_back((*l) * (*r));
//         l++;
//         r--;
//     }
//     // for(auto i:b){
//     //     cout << i << ' ';
//     // }
//     sort(b.begin(), b.end());
//     cout<<*--b.end()-*b.begin();
//     return 0;
// }

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
// const int N = 202020;
// vector<int> g[N];
// int ans;
// int n;
// int sz[N];

// void dfs(int x,int fa){
//     sz[x] = 1;
//     for(auto i:g[x]){
//         if(i!=fa){
//             dfs(i, x);
//             sz[x] += sz[i];
//         }
//     }
//     if(x!=1 && sz[x]%2==0)
//         ans++;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     if(n&1){
//         cout << -1;
//         return 0;
//     }
//     for (int i = 1; i < n;i++){
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//     dfs(1, 0);
//     cout << ans;
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
const int N = 1005;
const int mod = 1e9 + 7;
LL pow10[N];
LL C[N][N];
int n, m;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 1000;i++){
        for (int j = 0; j <= 1000;j++){
            if(i==j || j==0)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    pow10[0] = 1;
    for (int i = 1; i < 1000;i++){
        pow10[i] = (pow10[i - 1] * 10) % mod;
    }
    cin >> n >> m;
    cin >> s;
    LL ans = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            ans += ((s[i] - '0') * pow10[m - j - 1] % mod * C[i][j] * C[n - i - 1][m - j - 1] % mod) % mod;
        }
    }
    cout << ans % mod;
    return 0;
}
