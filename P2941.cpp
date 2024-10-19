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
const int N = 505, M = 1e6 + 10;
int n;
int w[N][N];
int h[N], e[M], ne[M], idx;
int dist[N][N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	in_stk[u] = true;
	for(int i = h[u]; ~i; i = ne[i]){
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
		}while(y != u);
	}	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	memset(h, -1, sizeof h);
	memset(dist, 0x3f, sizeof dist);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			int a = id[i], b = id[j];
			if(a != b){
				dist[a][b] = dist[b][a] = min(dist[a][b], x);
			}
		}
	}
	int ans = inf;
	for(int i = 1; i <= scc_cnt; i++){
		int res = 0;
		for(int j = 1; j <= scc_cnt; j++){
			if(i != j) res += dist[i][j];
		}
		ans = min(ans, res);
	}
	cout << ans * 2;
	return 0;
}