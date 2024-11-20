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
const int N = 5e5 + 10;
int n, m;
LL a[N];

struct Node{
	int l, r;
	LL sum, d;
}tr[N * 4];


LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &l, Node &r){
	u.sum = l.sum + r.sum;
	u.d = gcd(l.d, r.d);
}

void pushup(int u){
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
	if(l == r) tr[u] = {l, r, a[l] - a[l - 1], a[l] - a[l - 1]};
	else{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int x, LL v){
	if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, tr[u].sum + v, tr[u].sum + v};
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}

Node query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u];
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(r <= mid) return query(u << 1, l, r);
		else if(l > mid) return query(u << 1 | 1, l, r);
		else{
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l , r);
			Node res;
			pushup(res, left, right);
			return res;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	string op;
	int l, r;
	LL d;
	while(m--){
		cin >> op >> l >> r;
		if(op == "C"){
			cin >> d;
			modify(1, l, d);
			if(r + 1 <= n) modify(1, r + 1, -d);
		}
		else{
			auto left = query(1, 1, l);
			Node right = {0, 0, 0, 0};
			if(l + 1 <= r) right = query(1, l + 1, r);
			cout << abs(gcd(left.sum, right.d)) << endl;
		}
	}
	return 0;
}