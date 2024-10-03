#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
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
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int cnt[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
	queue<int> q;
	q.push(0);
	st[0] = true;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i];
			if(dist[j] < dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] > n + 1) return true;
				if(!st[j]){
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int a, b, c;
			cin >> a >> b >> c;
			add(b, a, c);
		}
		else if(op == 2){
			int a, b, c;
			cin >> a >> b >> c;
			add(a, b, -c);
		}
		else{
			int a, b;
			cin >> a >> b;
			add(a, b, 0), add(b, a, 0);
		}
	}
	for(int i = 1; i <= n; i++){
		add(0, i, 1);
	}
	if(spfa()) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}