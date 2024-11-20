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
	int minn = 101;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i != n - 1) minn = min(minn, a[i]);
	}
	int sum = 0;
	sum += a[n - 1];
	sum += minn;
	cout << sum << endl;
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