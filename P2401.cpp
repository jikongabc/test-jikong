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
const int N = 1010;
const int mod = 2015;
int n, k;
int dp[N][N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) dp[i][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j + 1) + dp[i - 1][j - 1] * (i - j)) % mod; 
		}
	}
	cout << dp[n][k];
	return 0;
}