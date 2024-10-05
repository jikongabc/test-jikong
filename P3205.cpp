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
const int mod = 19650827;
int n;
int a[N];
LL dp[N][N][2];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) dp[i][i][0] = 1;
	for(int len = 1; len <= n; len++){
		for(int i = 1; i + len - 1 <= n; i++){
			int j = i + len - 1;
			if(a[i] < a[i + 1]) dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % mod;
			if(a[i] < a[j]) dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % mod;
			if(a[j] > a[j - 1]) dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % mod;
			if(a[j] > a[i]) dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][0]) % mod;
		}
	}
	cout << (dp[1][n][0] + dp[1][n][1]) % mod;
	return 0;
}