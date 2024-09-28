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
const int N = 505, M = 1100;
int n = 500, m;
int g[N][N];
int d[N];
int ans[M], cnt;

void dfs(int u){
	for(int i = 1; i <= n; i++){
		if(g[u][i]){
			g[u][i]--, g[i][u]--;
			dfs(i);
		}
	}
	ans[++cnt] = u;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a][b] ++, g[b][a] ++;
		d[a]++, d[b]++;
	}
	int start = 1;
	while(!d[start]) start++;
	for(int i = 1; i <= n;  i++){
		if(d[i] & 1){
			start = i;
			break; 
		}
	}
	dfs(start);
	for(int i = cnt; i; i--) cout << ans[i] << endl; 
	return 0;
}