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
const int mod = 1e9 + 7;
int n, m, kn;
LL dp[205][205];
string a, b;
LL sum[205][205];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> kn;
	cin >> a >> b;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = m; j >=0; j--){
			for(int k = 0; k <= kn; k++){
				if(j > 0 && k > 0) dp[j][k] = (dp[j][k] + (sum[j][k] = a[i-1] == b[j-1] ? sum[j-1][k] + dp[j-1][k-1] : 0) ) % mod;
			}
		}
	}
	cout << dp[m][kn];
	return 0;
}