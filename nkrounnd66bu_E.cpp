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
const int N = 2e5 + 10;
int n, m;
int a[N];
int fa[N], cnt[N];
LL sum[N];

int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void merge(int a, int b){
	int pa = find(a), pb = find(b);
	if(pa == pb) return;
	if(pa > pb) swap (pa, pb);
	fa[pa] = pb;
	sum[pb] += sum[pa];
	cnt[pb] += cnt[pa];
}

int main(){
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		fa[i] = i;
		cnt[i] = 1;
		sum[i] = a[i];
	}
	while(m--){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int l, r;
			scanf("%d%d", &l, &r);
			while(l < r){
				merge(l, l + 1);
				l = find(l);
			}
		}	
		else{
			int x;
			scanf("%d", &x);
			int p = find(x);
			printf("%.10lf\n", sum[p] * 1.0 / cnt[p]);
		}
	}
	return 0;
}