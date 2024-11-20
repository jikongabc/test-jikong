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
const int N = 2e5 + 10;
int n;
int a[N];
int dp[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i = 0; i <= n; i++){
		int idx = i + a[i] - 1;
		if(idx <= n) dp[idx] = min(dp[idx], dp[i - 1] + 1);
		idx = i - a[i] + 1;
		if(idx > 0) dp[i] = min(dp[i], dp[idx - 1] + 1);
	}
	if(dp[n] == inf) cout << -1 << endl;
	else cout << dp[n] << endl;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}