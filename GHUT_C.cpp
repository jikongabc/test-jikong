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
bool st[N][N];
char g[N][N];
int sx, sy, ex, ey;

bool bfs(){
	queue<PII> q;
	q.push({sx, sy});
	st[sx][sy] = 1;
	while(!q.empty()){
		auto [x, y] = q.front();
		if(x == ex && y == ey) return true;
		q.pop();
		for(int i = 0; i < 4; i++){
			int a = x + dx[i], b = y + dy[i];
			if(a >= n || a < 0 || b >= m || b < 0) continue;
			if(st[a][b]) continue;
			if(a == ex && b == ey) return true;
			if(g[a][b] == '*') continue;
			q.push({a, b});
			st[a][b] = 1;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}	
	cin >> sx >> sy >> ex >> ey;
	sx--, sy--, ex--, ey--;
	if(bfs()) cout << "Yes";
	else cout << "No";
	return 0;
}