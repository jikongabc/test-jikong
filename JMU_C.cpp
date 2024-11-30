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
int l, r;
int dp[N];
int g[N];

void solve(){	
	cin >> l >> r;
	cout << dp[r] - dp[l - 1] << endl;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int i = 1; i < N; i++){
		for(int j = i; j < N; j += i){
			g[j]++;
		}
	}
	for(int i = 1; i < N; i++){
		dp[i] = dp[i - 1] + (g[i] <= 4);
	}
	while(T--){
		solve();
	}
	return 0;
}