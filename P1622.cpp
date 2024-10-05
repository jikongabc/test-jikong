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
const int N = 105;
int n, m;
int a[N];
int dp[N][N];
// dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j] + a[j+1] - a[i-1] -1 -1) 

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	a[0] = 0, a[m + 1] = n + 1;
	for(int len = 1; len <= m; len++){
		for(int i = 1; i + len - 1 <= m; i++){
			int j = i + len - 1;
			dp[i][j] = inf;
			for(int k = i; k <= j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[j + 1] - a[i - 1] - 1 - 1);
			}
		}
	}
	cout << dp[1][m];
	return 0;
}