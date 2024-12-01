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
const int N = 1e6 + 10;
int hp, a, b, c, d;
int k[N];

void solve(){
	cin >> hp >> a >> b >> c >> d;
	for(int i = 1; i <= hp; i++){
		cin >> k[i];
	}
	vector<LL> dp(hp + 1, 1e18);
	dp[hp] = 0;
	for(int i = hp; i >= 0; i--){
		dp[max(0, i - b)] = min(dp[max(0, i - b)], dp[i] + a);
		dp[max(0, i - d)] = min(dp[max(0, i - d)], dp[i] + c);
		if(i - 4 * b >= 1){
			dp[max(0, i - 4 * b - k[i - 4 * b] - d)] = min(dp[max(0, i - 4 * b - k[i - 4 * b] - d)], dp[i] + 4 * a + c);
		}
	}
	cout << dp[0] << endl;
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