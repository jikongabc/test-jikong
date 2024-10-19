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
const int N = 1e6 + 10, M = 3e6 + 10;
const int dx[] = {0, 1}, dy[] = {1, 0};
int n, m, cnt;
int g[505][505];
int h[N], hs[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, id[N], sz[N];
int res1, res2;
bool st[N];
int din[N], dout[N];

int get(int x, int y){
	return m * (x - 1) + y;
}

void add(int h[], int a,int b){
	e[idx] = b,ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	in_stk[u] = true;
	for(int i = h[u]; ~i; i= ne[i]){
		int j = e[i];
		if(!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
	}
	if(dfn[u] == low[u]){
		int y;
		scc_cnt++;
		do{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sz[scc_cnt]++;
		}while(y != u);
	}
}

void dfs(int u){
	st[u] = true;
	for(int i = hs[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			dfs(j);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> g[i][j];
		}
	}
	memset(h, -1,sizeof h);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int t1 = get(i, j);
			for(int k = 0; k < 2; k++){
				int a = i + dx[k], b = j + dy[k];
				if(a > n || b > m) continue;
				int t2 = get(a, b);
				if(g[a][b] > g[i][j]){
					add(h, t2, t1);
				}
				else if(g[a][b] < g[i][j]){
					add(h, t1, t2);
				}
				else{
					add(h, t1, t2), add(h, t2, t1);
				}
			}
		}
	}
	for(int i = 1; i <= n * m; i++){
		if(!dfn[i]) tarjan(i);
	}
	// memset(hs, -1, sizeof hs);
	for(int i = 1; i <= n * m; i++){
		for(int j = h[i]; ~j; j = ne[j]){
			int k = e[j];
			int a = id[i], b = id[k];
			if(a != b) dout[a]++, din[b]++;
		}
	}
	for(int i = 1; i <= scc_cnt; i++){
		if(!din[i]) res1++;
		if(!dout[i]) res2++;
	}
	if(scc_cnt == 1){
		cout << 0;
		return 0;
	}
	cout << max(res1, res2);
	// for(int i = 1; i <= scc_cnt; i++){
	// 	if(!st[i]){
	// 		dfs(i);
	// 		res++;
	// 	}
	// }
	// cout << res - 1 << endl;
	return 0;
}