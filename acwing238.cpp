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
const int N = 3e5 + 10;
int n, m;
int fa[N], d[N], sz[N];

int find(int x){
	if(fa[x] != x){
		int root = find(fa[x]);
		d[x] += d[fa[x]];
		fa[x] = root;
	}
	return fa[x];
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i = 1; i <= N; i++){
		fa[i] = i;
		sz[i] = 1;
	}
	cin >> m;
	while(m--){
		string op;
		int a, b;
		cin >> op >> a >> b;
		if(op == "M"){
			int pa = find(a), pb = find(b);
			if(pa != pb){
				d[pa] = sz[pb];
				sz[pb] += sz[pa];
				fa[pa] = pb;
			}
		}
		else{
			int pa = find(a), pb = find(b);
			if(pa != pb){
				cout << -1 << endl;
			}
			else{
				cout << max(0, abs(d[a] - d[b]) - 1) << endl;
			}
		}
	}
	return 0;
}