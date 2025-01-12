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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
// const int N =  ;

LL qmi(LL a, LL b){
	if(a == 0) return 0;
	LL res = 1;
	while(b){
		if(b & 1){
			if(res > lnf / a) return lnf;
			res = res * a;
		} 
		if(b > 1 && a > lnf / a) return lnf;
		a = a * a;
		b >>= 1;
	}
	return res;
}

bool check(LL mid, LL n, LL k){
	LL res = qmi(mid, k);
	return res >= n || res < 0;
}

void solve(){
	LL n, k;
	cin >> n >> k;
	LL l = 1, r = n;
	while(l < r){
		LL mid = l + r >> 1;
		if(check(mid, n, k)) r = mid;
		else l = mid + 1;
	}
	LL res = l;
	LL diff1 = abs(n - qmi(l, k));
	LL diff2 = abs(n - qmi(l - 1, k));
	if(l > 1 && diff2 < diff1) res = l - 1;
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