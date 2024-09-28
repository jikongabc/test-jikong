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
const int N = 1e5 + 10,M = 4e5 + 10;
int n, m;
int type;
int h[N], e[M], ne[M], idx;
int din[N], dout[N];
int ans[M], cnt;
bool st[M];

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
	while(~h[u]){
		int i = h[u];
		h[u] = ne[i];
		if(st[i]) continue;
		st[i] = true;
		if(type == 1) st[i^1] = true;
		dfs(e[i]);
			if(i & 1) t *= -1;
			ans[++cnt] = t;
		}
		else ans[++cnt] = i + 1;
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> type;
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		add(a, b);
		dout[a]++,din[b]++;
		if(type == 1) add(b, a);
	}
	if(type == 1){
		for(int i = 1; i <= n; i++){
			if(din[i] + dout[i] &1){
				cout << "NO";
				return 0;
			}
		}
	}	
	else{
		for(int i = 1; i <= n; i++){
			if(din[i] != dout[i]){
				cout << "NO";
				return 0;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(h[i] != -1){
			dfs(i);
			break;
		}
	}	
	if(cnt < m){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i = cnt; i; i--){
		cout << ans[i] << ' ';
	}
	return 0;
}