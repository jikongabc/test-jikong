// #include <iostream>
// #include <sstream>
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
// typedef pair<PII, int> PIII;
// const int N = 1e5 + 10;
// int n, q;
// int a[N];
// int cnt1[N][200];
// int cnt(int x){
//     unordered_map<int, int> primes;
//     for (int i = 2; i <= x / i;i++){
//         while(x%i==0){
//             x /= i;
//             primes[i]++;
//         }
//     }
//     if(x>1)
//         primes[n]++;
//     int res = 1;
//     for(auto i:primes)
//         res *= (i.second + 1);
//     return res;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> q;
//     for (int i = 1; i <= n;i++){
//         cin >> a[i];
//         a[i] = cnt(a[i]);
//         for (int j = 1; j <= 200;j++){
//             if(a[i]==j)
//                 cnt1[i][j] = cnt1[i - 1][j] + 1;
//             else
//                 cnt1[i][j] = cnt1[i - 1][j];
//         }
//     }
//     while(q--){
//         int l, r;
//         cin >> l >> r;
//         LL res = 0;
//         for (int i = 1; i <= 200;i++){
//             LL j = cnt1[r][i] - cnt1[l - 1][i];
//             if(j)
//                 res += j * (j - 1) / 2;
//         }
//         cout << res << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <sstream>
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
// typedef pair<PII, int> PIII;
// const int N = 2e5 + 10;
// int n;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     if(n<8){
//         cout << -1;
//         return 0;
//     }
//     int i;
//     for (i = 1; i <= n - 4;i++)
//         cout << i + 4 << ' ';
//     if(i%2)
//         cout << 1 << ' ' << 2 << ' ' << 3 << ' ' << 4;
//     else
//         cout << 2 << ' ' << 1 << ' ' << 4 << ' ' << 3;
    
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
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
typedef pair<PII, int> PIII;
const int N = 1e5 + 10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}