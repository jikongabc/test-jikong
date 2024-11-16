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
// const int N =  ;
int a[20];
int n, x;
int res;

void dfs(int u, int t1, int t2, int np, int sum, int k){
	if(u == n){
		res = max(res, sum);
		return;
	}
	for(int i = 1; i <= 4; i++){
		if(i == t1 || i == t2) continue;
		if(i == 1) dfs(u + 1, 1, t1, np, sum + a[u] * k, 1);
		if(i == 2) dfs(u + 1, 2, t1, np + x, sum, 1);
		if(i == 3) dfs(u + 1, 3, t1, np, sum + np * k, 1);
		if(i == 4) dfs(u + 1, 4, t1, np, sum, 2);
	}	
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	dfs(0, 0, 0, 0, 0, 1);
	cout << res;
	return 0;
}