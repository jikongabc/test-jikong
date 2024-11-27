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
int n;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> res;
	int num = 50;
	for(int i = 26; i >= 1; i--){
		int t = (1 << i) - 1;
		while(n >= t){
			for(int j = 0; j < i; j++){
				res.push_back(num);
			}
			n -= t;
			num--;
		}
	}
	cout << res.size() << endl;
	for(auto i : res){
		cout << i << ' ';
	}
	return 0;
}

// 17
// 1 0 0 0 1

// 2 2 2 2 3 7