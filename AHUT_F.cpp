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
int n, m;
int a[N], b[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
	}
	while(m--){
		int l, r;
		cin >> l >> r;
		cout << b[r] - b[l - 1] << endl;
	}
	return 0;
}