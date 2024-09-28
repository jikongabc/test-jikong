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
const int N = 2010, M = 1e6 +10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int q[N];
int d[N];
int dist[N];
bool st[N];

void add(int a,int b,int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
	d[b]++;
}

void topsort(){
	int hh = 0,tt = -1;
	for(int i = 1; i <= n + m; i++){
		if(!d[i]){
			q[++tt] = i;
		}
	}
	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i];
			if(--d[j] == 0) q[++tt] = j;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; i++){
		memset(st, false, sizeof st);
		int cnt = 0;
		cin >> cnt;
		int start = n, end1 = 1;
		while(cnt--){
			int stop;
			cin >> stop;
			start = min(start, stop);
			end1 = max(end1, stop);
			st[stop] = true;
		}
		int ver = n + i;
		for(int j = start; j <= end1; j++){
			if(st[j]) add(ver, j, 1);
			else add(j, ver, 0);
		}
	}
	topsort();
	for(int i = 1; i <= n; i++) dist[i] = 1;
	for(int i = 0;i < n + m; i++){
		int j = q[i];
		for(int k = h[j]; ~k; k = ne[k]){
			dist[e[k]] = max(dist[e[k]], dist[j] + w[k]);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, dist[i]);
	}
	cout << res;
	return 0;
}