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
const int N = 1010;

void solve(){
	int n, m;
	cin >> n >> m;
	if(n == m) cout << "Success!";
	else cout << "Fail!";
	if(m) cout << "Lala has been released:";
	else{
		cout << "Lala did not release magic.\n";
		return;
	} 
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		cout << s ;
		if(i != m - 1) cout << ",";
	}
	cout << ".\n";
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