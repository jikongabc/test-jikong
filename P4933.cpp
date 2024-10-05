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
const int N = 1e3 + 10, M = 2e4 + 10;
const int mod = 998244353;
int n;
int a[N];
LL sum;
LL dp[N][M * 2]; // d += M
// dp[i][j] += dp[1 ~ i-1][j]; 
// sum += dp

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sum = n;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			dp[j][a[j] - a[i] + M] = (dp[j][a[j] - a[i] + M] + 1) % mod;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			dp[i][a[i] - a[j] + M] = (dp[i][a[i] - a[j] + M] + dp[j][a[i] - a[j] + M]) % mod;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= M * 2; j++){
			sum = (sum + dp[i][j]) % mod;
		}
	}
	cout << sum;
	return 0;
}