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
int n;
int x;
int a[N];

void solve(){
	unordered_map<int, int> cnt;
	unordered_map<int, int> cnt1;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int t = 0;
	while(t < N){
		if(cnt[t] > 1){
			int tt = t % x;
			cnt1[tt] += cnt[t] - 1;
			cnt[t] = 1;
		}
		if(cnt[t] == 0){
			int tt = t % x;
			if(cnt1[tt] > 0) {
				cnt[tt]--;
				cnt[t] = 1;
			}
			else{
				cout << t << endl;
				return;
			}
		}
		// while(cnt[t] > 1){
		// 	// int tt = t;
		// 	// while(cnt.count(tt) != 0) tt += x;
		// 	// cnt[tt]++;
		// 	// cnt[t]--;
		// 	cnt[t + x] ++;
		// 	cnt[t]--;
		// }
		t++;
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}