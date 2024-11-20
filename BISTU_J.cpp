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
int n;
int a[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int t = n - 1;
	int cnt = 0;
	while(t - a[t] >= -1 && t >= 0){
		t -= a[t];
		cnt++;
	}
	// cout << t << endl;
	if(t == -1){
		cout << cnt << endl;
	}
	else cout << -1 << endl;
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