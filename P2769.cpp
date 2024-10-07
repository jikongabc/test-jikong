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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 5010;
int n, m;
int a[N], b[N];


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	vector<vector<LL>> dp(2, vector<LL>(m + 1, 1e18));
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	dp[1][1] = abs(a[1] - b[1]);
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i & 1][j] = min(dp[(i - 1) & 1][j - 1], dp[(i - 1) & 1][j]) + (LL)abs(a[i] - b[j]);
		}
	}
	cout << dp[n & 1][m];
	return 0;
}