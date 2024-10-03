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
const int N = 1e5 + 10, M = 5e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int din[N];

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
	if(low[u] == dfn[u]){
		int y;
		++scc_cnt;
		do{
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
		}while(y != u);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) tarjan(i);
 	}
 	for(int i = 1; i <= n;i++){
 		for(int j = h[i]; ~j; j = ne[j]){
 			int k = e[j];
 			int a = id[i], b = id[k];
 			if(a != b) din[b]++;
 		}
 	}
 	int res = 0;
 	for(int i = 1; i<= scc_cnt; i++){
 		if(!din[i]) res++;
 	}
 	cout << res;
	return 0;
}