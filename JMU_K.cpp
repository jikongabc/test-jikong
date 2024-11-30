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
const int N = 21;
int n;

void solve(){
	cin >> n;
	bool flag = false;
	for(int i = 0; i < 20; i++){
		int t = n >> i & 1;
		if(!flag){
			if(t) cout << "L";
			else{
				flag = true;
				cout << "R";
			}
		}
		else{
			if(t){
				cout << "R";
				flag = false;
			}
			else cout << "L";
		}
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << 21 << endl;
	cout << 0 << endl;
	for(int i = 0; i < 20; i++){
		for(int j = 1; j <= i + 2; j++){
			if(j & 1) cout << (1 << i) << ' ';
			else cout << 0 << ' ';
		}
		cout << endl;
	}
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}