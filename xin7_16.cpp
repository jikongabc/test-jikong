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
int n, k;
string s;

void solve(){
	cin >> n >> k;
	cin >> s;
	int t = k - 1;
	int cnt = 0;
	while(t >= 0 && t < n){
		cnt++;
		if(s[t] == '<'){
			s[t] = '>';
			t--;
		}
		else{
			s[t] = '<';
			t++;
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