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
const int mod = 1000;
int n;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	vector<vector<int>> dp(2, vector<int>(10, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
		for(int j = 0; j < 8; j++){
			if(j != 5)
				dp[i & 1][j] = dp[(i - 1) & 1][(j - 1 + 8) % 8] % mod;
			if(j != 3) 
				dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][(j + 1) % 8]) % mod;
		}
	}
	cout << dp[n & 1][4];
	return 0;
}