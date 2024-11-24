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
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 4e5 + 10, M = 2e6 + 10;
int m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root, res;
char p[5][N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
	dfn[u] = low[u] = ++timestamp;
	int cnt = 0;
	bool is_cut = false;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!dfn[j]){
			tarjan(j);
			low[u] = min(low[u], low[j]);
			if(dfn[u] <= low[j]){
				cnt++;
				if(u != root) is_cut = true;
			}
		}
		else{
			low[u] = min(low[u], dfn[j]);
		}
	}
	if(u == root){
		if(cnt > 1) is_cut = true;
	}
	if(is_cut) res++;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m;
	memset(h, -1, sizeof h);
	string s[2];
	cin >> s[0] >> s[1];
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= m + 1; j++){
			p[i][j] = 'x';
		}
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= m; j++){
			p[i][j] = s[i - 1][j - 1];
		}
	} 
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && p[i][j] == '.' && p[i + 1][j] == '.'){
				int a = j, b = m + j;
				add(a, b), add(b, a); 
			} 
			if(i < m && p[i][j] == '.' && p[i][j + 1] == '.'){
				int a = (i - 1) * m + j, b = (i - 1) * m + j + 1;
				add(a, b), add(b, a);
			}
		}
	}
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= m; j++){
			if(p[i][j] == '.'){
				root = (i - 1) * m + j;
				if(!dfn[root]){
					tarjan(root);
				}
			}
		}
	}
	// cout << res << endl;
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= m; j++){
			if(p[i][j] == '.' && p[i - 1][j] == 'x' && p[i + 1][j] == 'x' && p[i][j - 1] == 'x' && p[i][j + 1] == 'x') res++;
		}
	}
	cout << res;
	return 0;
}