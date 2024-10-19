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
const int N = 1e5 + 10, M = 4e5 + 10;
int m1, m2;
unordered_map<string, int> ma;
int cnt;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, sz[N], id[N];
PII body[N];

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
			sz[scc_cnt]++;

		}while(y != u);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m1;
	memset(h , -1, sizeof h);
	for(int i = 0; i < m1; i++){
		string a, b;
		cin >> a >> b;
		if(ma.count(a) == 0) ma[a] = ++cnt;
		if(ma.count(b) == 0) ma[b] = ++cnt;
		add(ma[a], ma[b]);
		// add(ma[b], ma[a]);
		body[i] = {ma[a], ma[b]};
	}
	cin >> m2;
	while(m2--){
		string a, b;
		cin >> a >> b;
		if(ma.count(a) == 0) ma[a] = ++cnt;
		if(ma.count(b) == 0) ma[b] = ++cnt;
		// add(ma[a], ma[b]);
		add(ma[b], ma[a]);
	}
	// cout << cnt << endl;
	for(int i = 1; i <= cnt; i++){
		if(!dfn[i]) tarjan(i);
	}
	// cout << scc_cnt << endl;
	for(int i = 0; i < m1; i++){
		int a = body[i].first, b = body[i].second;
		if(id[a] == id[b]) cout << "Unsafe\n";
		else cout << "Safe\n";
	}
	return 0;
}