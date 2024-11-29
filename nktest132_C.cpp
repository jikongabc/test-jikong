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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
LL fact[N], infact[N], pow2[N];
int n, k;

LL qmi(int a, int b, int p){
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

void solve(){
    cin >> n >> k;
    if(n & 1){
        cout << 0 << endl;
        return;
    }
    if(k > n || k < 0){
        cout << 0 << endl;
        return;
    }
    LL C_nk = fact[n] * infact[k] % mod * infact[n - k] % mod;
    LL C_mk = 0;
    int m = n / 2;
    if(k <= m){
        C_mk = fact[m] * infact[k] % mod * infact[m - k] % mod;
    }
    LL res = (C_nk - (C_mk * pow2[k] % mod)) % mod; // 改之前
    LL res = (C_nk - C_mk * pow2[k] % mod + mod) % mod; // 改之后
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    fact[0] = infact[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    infact[N - 1] = qmi(fact[N - 1], mod - 2, mod);
    for (int i = N - 2; i >= 1; i--)
    {
        infact[i] = infact[i + 1] * (i + 1) % mod;
    }
    while(T--){
        solve();
    }
    return 0;
}
