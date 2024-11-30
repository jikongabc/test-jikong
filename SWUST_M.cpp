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
const int N = 1e5 + 10;
int n;
int a[N];

void solve(){
	cin >> n;
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	a[0] = maxn;
	LL res = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] < a[i - 1]) res += a[i - 1] - a[i];
	}
	cout << res << endl;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}