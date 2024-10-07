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
const int N = 2010;
int n, m, k;
string a, b;
int dp[N][N];


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> a >> b >> k;
	n = a.size(), m = b.size();
	a = "*" + a, b = "#" + b;
	for(int i = 1 ; i <= n; i++) dp[i][0] = dp[i - 1][0] + k;
	for(int i = 1 ; i <= m; i++) dp[0][i] = dp[0][i - 1] + k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = min({dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + (int)(abs(a[i] - b[j]))});
		}
	}
	cout << dp[n][m];
	return 0;
}