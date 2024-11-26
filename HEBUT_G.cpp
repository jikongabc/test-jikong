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
#define int long long
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int N = 1e5 + 10, M = 4e5 + 10;
int n, p, q;
int h[N], e[M], ne[M], w[M], idx; 
int dist[N], dist1[N];
bool st[N], sst[N];
int fa[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = 1;
		for(int i = h[ver]; ~i; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[ver] + w[i]){
				dist[j] = dist[ver] + w[i];
				q.push({dist[j], j});
			}
		}
	}
	return;
}

void dfs(int u){
	sst[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(!sst[j]){
			dist1[j] = dist1[u] + w[i];
			dfs(j);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> p >> q;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 0; i < n + p - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
		int pa = find(a), pb = find(b);
		if(pa != pb && a != 1 && b != 1){
			fa[pa] = pb;
		}
	}
	dijkstra();
	dfs(1);
	// for(int i = 1; i <= n; i++){
	// 	cout << "d"<< i <<":" << dist1[i] << endl;
	// }
	while(q--){
		int a, b;
		cin >> a >> b;
		int pa = find(a), pb = find(b);
		if(pa != pb){
			cout << dist[a] + dist[b] << endl;
		}
		else{
			// cout << "000" << ' ';
			// cout << dist[a] + dist[b] << ' ';
			cout << min(abs(dist1[a] - dist1[b]), dist[a] + dist[b]) << endl;
		}
	}
	return 0;
}