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
const int N = 55;
int n, m;
string g[N];
int x, y;
int k;
set<PII> op;
LL dist[N][N];

bool pd(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m && g[x][y] != '0';
}

void bfs(int x, int y){
	queue<PII> q;
	q.push({x, y});
	dist[x][y] = 0;
	while(!q.empty()){
		auto [x1, y1] = q.front();
		q.pop();
		for(auto &i : op){
			int a = x1 + i.first, b = y1 + i.second;
			if(!pd(a, b)) continue;
			if(~dist[a][b]) continue;
			dist[a][b] = dist[x1][y1] + 1;
			q.push({a, b});
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(dist, -1, sizeof dist);
	for(int i = 1; i <= n; i++){
		cin >> g[i];
		g[i] = " " + g[i];
	}	
	cin >> x >> y;
	cin >> k;
	while(k--){
		int a, b;
		cin >> a >> b;
		if(abs(a) > n || abs(b) > m) continue;
		op.insert({a, b});
	}
	if(pd(x, y)) bfs(x, y);
	if(g[x][y] == '0'){
		dist[x][y] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++){
			if(dist[i][j] == -1) cout << "inf ";
			else cout << dist[i][j] << ' ';
		}
		if(dist[i][m] == -1) cout << "inf";
		else cout << dist[i][m];
		cout << endl;
	}
	return 0;
}