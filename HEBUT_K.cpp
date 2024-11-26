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
int a[N], b[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int cnt = 0;
	int cnt1 = 0;
	for(int i = 0, j = 0; i < n; i++){
		while(a[i] > b[j] && j < n){
			j++;
			cnt1++;
		} 
		if(j < n){
			// cout << i << ' ';
			cnt++;
			j++;
		}
			// cout << "j:" <<j << endl;
	}
	// cout << cnt1 << endl;

	// cout << endl;
	// cout << cnt << endl;
	if(cnt > n / 2) cout << "Yasmine\n";
	else cout << "Rheanna\n";
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



// 3 4 8 9 10 12 13
// 1 2 5 6  7 11 14



// 13 12 10 9 8 4 3
// 14 1  11 2 5 6 7