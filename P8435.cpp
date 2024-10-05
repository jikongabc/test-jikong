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
const int N = 5e5 + 10, M = 4e6 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
int root, cnt;
vector<int> dcc[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	if(u == root && h[u] == -1){
		dcc_cnt++;
		dcc[dcc_cnt].push_back(u);
		return;
	}
	int cnt = 0;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if(dfn[u] <= low[j]){
				cnt++;
				dcc_cnt++;
				int y;
				do{
					y = stk[top--];
					dcc[dcc_cnt].push_back(y);
				}while(y != j);
				dcc[dcc_cnt].push_back(u);
			}
		}
		else low[u] = min(low[u], dfn[j]);
	}
	if(u == root && cnt == 0){
		dcc_cnt ++;
		dcc[dcc_cnt].push_back(u);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	for(root = 1; root <= n; root++){
		if(!dfn[root]) tarjan(root);
	}
	cout << dcc_cnt << endl;
	for(int i = 1; i <= dcc_cnt; i++){
		cout << dcc[i].size() <<' ';
		for(auto j : dcc[i]) cout << j << ' ';
		cout << endl;
	}
	return 0;
}