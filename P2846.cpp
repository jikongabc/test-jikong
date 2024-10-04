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
const int N = 1e5 + 10;
int n, m;
int a[N];

struct Node{
	int l, r;
	int sum;
	int lz;
}tr[N * 4];

void pushup(int u){
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
	auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
	if(root.lz){
		left.lz ^= 1, left.sum = left.r - left.l + 1 - left.sum;
		right.lz ^= 1, right.sum = right.r - right.l + 1 - right.sum;
		root.lz = 0;
 	}
}

void build(int u, int l, int r){
	if(l == r) tr[u] = {l, r, 0, 0};
	else{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
		tr[u].lz ^= 1;
	}
	else{
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if(l <= mid) modify(u << 1, l, r);
		if(r > mid) modify(u << 1 | 1, l, r);
		pushup(u);
	}
}

int query(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	int sum = 0;
	if(l <= mid) sum = query(u << 1, l, r);
	if(r > mid) sum += query(u << 1 | 1, l, r);
	return sum;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	build(1, 1, n);
	while(m--){
		int op;
		cin >> op;
		if(!op){
			int l, r;
			cin >> l >> r;
			modify(1, l, r);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << endl;
		}
	}
	return 0;
}