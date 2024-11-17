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
const int N = 1e6 + 10;
int a[N];

void solve(){
	int n, k;
	cin >> n >> k;
	bool flag = true;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] < a[i - 1]) flag = false;
	} 
	if(k <= 1 && !flag) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}