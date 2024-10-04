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
int n, m;
LL a[N];

struct Node{
	int l, r;
	LL sum;
	LL add;
}tr[N * 4];

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
	if(root.add){
		left.add += root.add, left.sum += (left.r - left.l + 1) * root.add;
		right.add += root.add, right.sum +=(right.r - right.l + 1) * root.add; 
		root.add = 0;
	}
}

void build(int u, int l, int r){
	if(l == r) tr[u] = {l, r, a[l], 0};
	else{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}	

void modify(int u, int l, int r, int d){
	if(tr[u].l >= l && tr[u].r <=r){
		tr[u].add += d;
		tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
	}
	else{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r, d);
		if(r > mid) modify(u << 1 | 1, l, r, d);
		pushup(u);
	}
}

LL query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	LL sum = 0;
	if(l <= mid) sum = query(u << 1, l, r);
	if(r > mid)	sum += query(u << 1 | 1, l, r);
	return sum;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	int op;
	while(m--){
		cin >> op;
		if(op == 1){
			int l, r, d;
			cin >> l >> r >> d;
			modify(1, l, r, d);
		}
		else if(op == 2 || op == 3){
			int d;
			cin >> d;
			if(op == 2) modify(1, 1, 1, d);
			else modify(1, 1, 1, -d);
		}
		else if(op == 4){
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << endl;
		}
		else cout << query(1, 1, 1) << endl;
	}
	return 0;
}