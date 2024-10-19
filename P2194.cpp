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
const int N = 1e5 + 10, M = 6e5 + 10;
const int mod = 1e9 + 7;
int n, m;
int h[N], hs[N], e[M], ne[M], idx;
int w[N], sw[N], cnt_ws[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, id[N], sz[N];
int dp1[N], dp2[N];

void add(int h[], int a, int b){
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
			sz[scc_cnt]++;
			if(w[y] < sw[scc_cnt]){
				sw[scc_cnt] = w[y];
				cnt_ws[scc_cnt] = 1;
			} 
			else if(w[y] == sw[scc_cnt]){
				cnt_ws[scc_cnt]++;
			}
		}while(y != u);
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	cin >> m;
	memset(h, -1, sizeof h);
	memset(hs, -1, sizeof hs);
	memset(sw, 0x3f, sizeof sw);
	while(m--){
		int a, b;
		cin >> a >> b;
		add(h, a, b);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	// for(int i = 1; i <= n; i++){
	// 	for(int j = h[i]; ~j; j = ne[j]){
	// 		int k = e[j];
	// 		int a = id[i], b = id[k];
	// 		if(a != b) add(hs, a, b);
	// 	}
	// }
	int res1 = 0, res2 = 1;
	for(int i = 1; i <= scc_cnt; i++){
		res1 = (res1 + sw[i]) % mod;
		res2 = (res2 * cnt_ws[i]) % mod;
	}
	cout << res1 << ' ' << res2;
	return 0;
}