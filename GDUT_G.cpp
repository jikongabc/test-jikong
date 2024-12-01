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
// 1 2 3 4 5 6
// 4 1 5 2 6 3

// 1 2 3 4 5 6 7
// 4 1 5 2 6 3 7

//1 2 3 4 5 6 7 8
//5 1 6 2 7 3 8 4

void solve(){
	cin >> n >> k;
	if(k > n / 2){
		cout << "NO";
	}
	else{
		cout << "YES" << endl;
		if(n & 1){
			for(int i = n / 2 + 1; i <= n - 1; i++){
				cout << i << ' ' << i - n / 2 << ' ';
			}
			cout << n << ' ';
		}
		else{
			for(int i = n / 2 + 1; i <= n; i++){
				cout << i << ' ' << i - n / 2 << ' ';
			}
		}
	}
	cout << endl;
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