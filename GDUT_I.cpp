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
const int N = 2e5 + 10, M = 1e6 + 10;
int n, m, k, w1;
int h[N], e[M], ne[M], w[M], idx;

struct Node{
	int dis, cnt, u;
	bool operator > (const Node & a) const{
		if(dis != a.dis) return dis > a.dis;
		return cnt > a.cnt;
	}
};

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void solve(){
	vector<bool> st(n + 1, false);
	vector<PII> dist(n + 1, {inf, inf});
	// memset(dist, 0x3f, sizeof dist);
	cin >> n >> m >> k >> w1;
	memset(h, -1, sizeof h);
	idx = 0;
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	auto dijkstra = [&] () -> void{
		dist[1] = {0, 0};
		priority_queue<Node, vector<Node>, greater<Node>> q;
		q.push({0, 0, 1});
		while(!q.empty()){
			auto [dis, cnt, ver] = q.top();
			q.pop();
			if(st[ver]) continue;
			st[ver] = 1;
			for(int i = h[ver]; ~i; i = ne[i]){
				int j = e[i];
				PII t = {dis + w[i], cnt};
				if(dist[j] > t){
					dist[j] = t;
					q.push({dis + w[i], cnt, j});
				}
			}
			for(auto p : {k, -k}){
				int j = ver + p;
				if(j >= 1 && j <= n && j != ver){
					PII t = {dis + w1, cnt + 1};
					if(dist[j] > t){
						dist[j] = t;
						q.push({dis + w1, cnt + 1, j});
					}
				}
			}
		}
	};
	dijkstra();
	if(dist[n].first == inf){
		cout << -1 << ' ' << -1 << endl;
		return;
	}
	cout << dist[n].first << ' ' << dist[n].second << endl;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}