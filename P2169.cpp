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
const int N = 2e5 + 10, M = 1e6 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
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
		++scc_cnt;
		do{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
		}while(y != u);
	}
}

int dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,1});
	dist[1] = 0;
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		int ver = t.second;
		for(int i = h[ver]; ~i; i = ne[i]){
			int j = e[i];
			if(id[ver] == id[j]) w[i] = 0;
			if(dist[j] > dist[ver] + w[i]){
				dist[j] = dist[ver] + w[i];
				q.push({dist[j], j});
			}
		}
	}
	return dist[n];
}	

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	cout << dijkstra();
	return 0;
}