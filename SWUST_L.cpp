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
int n;
string s;

void solve(){
	cin >> n;
	cin >> s;
	int pos = 0;
	map<char, int> ma;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			cout << "shameimaru\n";
			return;
		}
	}
	while(ma.count(s[pos]) == 0 && pos < n){
		ma[s[pos]] = 1;
		int t = n - pos - 1;
		if(t % 2 == 0 && pos < n - 1){
			if(s.substr(pos + 1, t / 2) == s.substr(pos + 1 + t / 2)){
				// cout << pos + 1<< endl;
				cout << "aya\n";
				return;			
			}
		}
		pos++;
	}
	cout << "shameimaru\n";
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