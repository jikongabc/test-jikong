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
const int mod = 1e9 + 7;
int n, q;
int a[N];
LL pre[N];
LL prepre[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		prepre[i] = prepre[i - 1] + pre[i];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		int midl = l + r - 1 >> 1;
		int midr = l + r >> 1;
		LL res = ((prepre[r] - prepre[midr - 1]) -(prepre[midl] - prepre[max(l - 2, 0)])) % mod;
		cout << res << endl;
	}
	return 0;
}