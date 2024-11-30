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
int n, z, s;

void solve(){
	cin >> n >> z >> s;
	LL res1 = 0 , res2 = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x > s) res1 = res1 - 2 >= 0 ? res1 - 2 : 0; 
		else res1 ++;
	}	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x > z) res2 = res2 - 2 >= 0 ? res2 - 2 : 0;
		else res2 ++ ; 
	}
	if(res1 > res2){
		cout << "zy\n";
	}
	else if(res1 == res2){
		cout << "none\n";
	}
	else cout << "sdy\n";
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