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
const int N = 2e5 + 10;
int n;
int a[N];
LL pre[N];
int dp[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	if(pre[n] % 3){
		cout << 0;
		return 0;
	}
	int t = pre[n] / 3;
	LL res = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > 0) dp[i] = cnt;
		else dp[i] = dp[i - 1];
		if(pre[i] == t) cnt++;
		else if(pre[i] == t * 2) res += dp[i];
	}
	cout << res;
	return 0;
}