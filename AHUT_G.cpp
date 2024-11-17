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
int n;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x != 1){
			if(i & 1) cout << 1 << endl;
			else cout << 2 << endl;
			return 0;
		}
	}
	if(n & 1) cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}