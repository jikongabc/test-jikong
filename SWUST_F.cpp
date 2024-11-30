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
int n, m;
string s, t;

void solve(){
	cin >> n >> m;
	cin >> s >> t;
	string res;
	for(int i = 0; i < n; i++){
		while(s[i] == s[i + 1]) i++;
		res.push_back(s[i]);
	}
	// cout << res << endl;
	if(res == t) cout << "YES\n";
	else cout << "NO\n";
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