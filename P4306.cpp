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
const int N = 2020, M = 4e6 + 10;
int n;
int h[N], rh[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, id[N], sz[N];
bitset<N> dp[N];
int din[N];

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
		}while(y != u);
		dp[scc_cnt][scc_cnt] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '1') add(h, i, j + 1);
		}
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= n; i++){
		for(int j = h[i]; ~j; j = ne[j]){
			int k = e[j];
			int a = id[i], b = id[k];
			if(a != b){
				add(rh, b, a);
				din[a]++;
			}
		}
	}
	queue<int> q;
	for(int i = 1; i <= scc_cnt; i++){
		if(din[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = rh[t]; ~i; i = ne[i]){
			int j = e[i];
			dp[j] |= dp[t];
			if(--din[j]){
				q.push(j);
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= scc_cnt; i++){
		for(int j = 1; j <= scc_cnt; j++){
			if(dp[i][j] == 1) res += sz[i] * sz[j]; 
		}
	}
	cout << res;
	return 0;
}