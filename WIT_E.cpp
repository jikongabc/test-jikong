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
const int N = 25;
int n, m, k;
__int128 fact[N];

LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}

void solve(){
	cin >> n >> m >> k;
	LL res1 = fact[m + k];
	LL res2 = fact[n + m + k - 1] / fact[n - 1];
	LL t = gcd(res1, res2);
	// cout << res1 << ' ' << res2 << endl;
	cout << res1 / t << ' ' << res2 / t << endl;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		fact[i] = fact[i - 1] * i;
	}
	while(T--){
		solve();
	}
	return 0;
}