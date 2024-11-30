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
// const int N =  ;


void solve(){
	int a, b;
	scanf("%d:%d", &a, &b);
	int cnt = 0;
	while(a / 10 != b % 10 || a % 10 != b / 10){
		b++;
		if(b == 60){
			b = 0;
			a++;
			if(a == 24) a = 0;
		}
		cnt++;
	}
	if(a < 10) cout << 0 << a <<":";
	else cout << a << ":";
	if(b < 10) cout << 0 << b << endl;
	else cout << b << endl;
	cout << cnt << endl;
}	


int main(){
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}