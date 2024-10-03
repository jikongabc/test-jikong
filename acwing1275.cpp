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
const int N = 2e5 + 10;
int n, m, p;
int last;

struct Node{
	int l, r;
	int v;
}tr[N * 4];

void build(int u, int l, int r){
	tr[u] ={l, r};
	if(l == r) return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushup(int u){
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

int query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <=r) return tr[u].v;
	int mid = tr[u].l + tr[u].r >> 1;
	int v = 0;
	if(l <= mid) v = query(u << 1, l, r);
	if(r > mid) v = max(v, query(u << 1 | 1, l, r));
	return v; 
}

void modify(int u, int x, LL v){
	if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m >> p;
	build(1, 1, m);
	while(m--){
		string op;
		int x;
		cin >> op >> x;
		if(op == "A"){
			modify(1, ++n, ((LL)last + x) % p);
		}
		else{
			last = query(1, n - x + 1, n);
			cout << last << endl;
		}
	}
	return 0;
}