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
const int N = 1010;
int tt, m;
int res;
PII a[1010];

void dfs(int u, int t, int sum){
	if(u == m ){
		if(t <= tt)
			res = max(res, sum);
		return;
	}
	dfs(u + 1, t, sum);
	dfs(u + 1, t + a[u].first, sum + a[u].second);
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> tt >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i].first >> a[i].second;		
	}
	dfs(0, 0, 0);
	cout << res;
	return 0;
}