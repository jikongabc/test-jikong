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
const int N = 1e5 + 10;
const int mod = 998244353;
int n;
LL a[N];
LL pre[N];
LL sum[N];

void solve(){
	cin >> n;
	LL res = 0;
	memset(pre, 0, sizeof pre);
	memset(sum, 0, sizeof sum);
	for(int i = n; i >= 1; i--){
		pre[i] = (pre[i + 1] + a[i]) % mod;
		sum[i] = (sum[i + 1] + a[i] * a[i] % mod) % mod;
	}
	// for(int i = 1; i <= n; i++){
	// 	for(int j = i; j <= n; j++){
	// 		res = (res + (a[j] - a[i]) * (a[j] - a[i]) % mod) % mod;
	// 	}
	// }
	// cout << res << endl;
	for(int i = 1; i <= n; i++){
		res = (res + (n - i + 1) * a[i] % mod * a[i] % mod + sum[i]) % mod;
		res = (res - 2 * a[i] * pre[i] % mod + mod) % mod;
	}
	cout << res % mod<< endl;  

}
// 1+1 + 1+2 + 1+3 + ... + 1+n
// 	  2+2 + 2+3 + ... + 2+n
// 	  	    3+3 + ... + 3+n





int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	a[1] = a[2] = 1;
	for(int i = 3; i < N; i++){
		a[i] = (a[i - 1] + a[i - 2]) % mod;
	}
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}	