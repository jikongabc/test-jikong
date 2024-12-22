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

	void solve(){
		int n;
		LL x, y;
		cin >> n >> x >> y;
		vector<int> a(n);
		LL sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}	
		sort(a.begin(), a.end());
		LL minn = sum - y;
		LL maxn = sum - x;
		LL cnt = 0;
		for(int i = 0; i < n - 1; i++){
			LL lower = minn - a[i];
			LL upper = maxn - a[i];
			int l = lower_bound(a.begin() + i + 1, a.end(), lower) - a.begin();
			int r = upper_bound(a.begin() + i + 1, a.end(), upper) - a.begin();
			if(l < n && l < r){
				cnt += r - l;
			}
		}
		cout << cnt << endl;
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