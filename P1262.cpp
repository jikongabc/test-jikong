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
const int N = 3010, M = 8005;
int n,m;
int h[N], e[M], ne[M], idx;
int x;
int w[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int res1;
LL res2;
int din[N];
int minn[N];
bool st[N];
queue<int> q;

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i];
			if(!st[j]){
				q.push(j);
				st[j] = true;
			}
				
		}
	}
}

void tarjan(int u){
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	in_stk[u] = true;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!dfn[j] && st[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j]) low[u] = min(low[u], dfn[j]);
	}
	if(dfn[u] == low[u]){
		int y;
		++scc_cnt;
		do{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sz[scc_cnt]++;
			if(w[y] != 0) minn[scc_cnt] = min(minn[scc_cnt], w[y]);
		}while(y != u);
	if(sz[scc_cnt] == 1 && !st[y]) res1 = min(res1, y);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	cin >> x;
	for(int i = 0; i < x; i++){
		int a, b;
		cin >> a >> b;
		w[a] = b;
		q.push(a);
		st[a] = true;
	}
	cin >> m;
	memset(h, -1, sizeof h);
	memset(minn, 0x3f, sizeof minn);
	res1 = inf;
	while(m--){
		int a, b;
		cin >> a >> b;
		add(a, b);
		// st[a] = true, st[b] = true;
		// cout << a << ' ' << b << endl;
	}
	bfs();
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	if(res1 < inf){
		cout << "NO\n";
		cout << res1;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = h[i]; ~j; j = ne[j]){
			int k = e[j];
			if(st[k] && st[i]){
				int a = id[i], b = id[k];
				if(a != b) din[b]++;
			}
			
		}
	}
	for(int i = 1; i <= scc_cnt; i++){
		// cout << sz[scc_cnt]<<' ';
		if(!din[i]) res2 += minn[i];
	}

	cout << "YES\n";
	cout << res2;
	return 0;
}