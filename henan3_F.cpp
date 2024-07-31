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
typedef pair<int, PII> PIII;
const int N = 1e6 + 10;
int n, k;
int cnt_1[N*2];

void init(){
    for (int i = 0; i < N;i++)
        cnt_1[i] = __builtin_popcount(i);
}

// int count_1(int n){
//     int cnt = 0;
//     while(n){
//         cnt += n & 1;
//         n >>= 1;
//     }
//     return cnt;
// }

// int count_different_bits(int a, int b)
// {
//     return __builtin_popcount(a ^ b);
// }

void solve(){
    cin >> n >> k;
    int now = n, res = 0;
    for (int i = 0; i < k;i++){
        now++;
        // res += count_1(now ^ (now - 1));
        // res += __builtin_popcount(now^(now - 1));
        res += cnt_1[now ^ (now - 1)];
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
