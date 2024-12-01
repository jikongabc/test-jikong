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
const int N = 1e6 + 10;
int n, k;
int a[N];

bool check(LL x){
	int cnt = 1;
	LL sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > x) return false;
		if(sum + a[i] <= x){
			sum += a[i];
		}
		else{
			sum = a[i];
			cnt++;
		}
	}
	return cnt <= k;
}

void solve(){
	cin >> n >> k;
	LL sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	LL l = 1, r = sum;
	while(l < r){
		LL mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
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