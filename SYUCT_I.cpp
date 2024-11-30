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
const int N = 1e4 + 10, M = 2e5 + 10;
int n, m;
int fa[N];
unordered_map<string, int> ma;
vector<PII> adj;
vector<int> g[N];
int ask[N];
int res[N];
bool st[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		string s;
		cin >> s;
		ma[s] = i;
	}
	for(int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;
		adj.push_back({ma[a], ma[b]});
		g[ma[a]].push_back(ma[b]);
		g[ma[b]].push_back(ma[a]);
	}
	int k;
	cin >> k;
	for(int i = 1; i <= k; i++){
		string s;
		cin >> s;
		ask[i] = ma[s];
		st[ask[i]] = true;
	}
	int ans = n - k;
	for(auto [a, b] : adj){
		if(!st[a] && !st[b]){
			int pa = find(a), pb = find(b);
			if(pa != pb){
				fa[pa] = pb;
				ans--;
			}
		}
	}
	for(int i = k; i >= 1; i--){
		res[i] = ans;
		set<int> s;
		for(auto it : g[ask[i]]){
			if(!st[it]){
				s.insert(find(it));
				int pa = find(ask[i]), pb = find(it);
				if(pa != pb){
					fa[pa] = pb;
				}
			}
		}
		ans -= (int)(s.size()) - 1;
		st[ask[i]] = false;
	}
	res[0] = ans;
	for(int i = 0; i <= k; i++){
		cout << res[i] << endl;
	}
	return 0;
}