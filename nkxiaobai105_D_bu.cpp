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
const int N = 2e5 + 10;
int n, m;
int a[N];
int fa[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		fa[i] = i;
	}	
	// memset(h, -1, sizeof h);
	while(m--){
		int a, b;
		cin >> a >> b;
		a = find(a), b = find(b);
		if(a != b) fa[a] = b;
	}
	vector<vector<int>> v(n + 1);
	for(int i = 1; i <= n; i++){
		v[find(i)].push_back(a[i]);
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(!v[i].size()) continue;
		map<int, int> mp;
		int maxn = 0;
		for(auto it : v[i]){
			mp[it]++;
			maxn = max(maxn, mp[it]);
		}
		res += v[i].size() - maxn;
	}
	cout << res;
	return 0;
}