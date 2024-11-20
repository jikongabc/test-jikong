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
const int N = 1e5 + 10;
int n;

void solve(){
	cin >> n;
	if(n == 3) cout << "1 -10 6 6 -10 1" << endl;
	else{
		cout << 3 - n << ' ';
		for(int i = 1; i <= n - 1; i++) cout << -1 << ' ' << 2 << ' ';
		cout << 1 << endl;
	}
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