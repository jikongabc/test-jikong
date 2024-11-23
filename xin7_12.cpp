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
const int N = 105;
int n, m;

int main(){
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	getchar();
	int res = 0;
	for(int i = 1; i <= n; i++){
		int t = 0;
		for(int j = 1; j <= m; j++){
			char c;
			scanf("%c", &c);
			// cout << c << ' ';
			if(c == '$') t = max(t, 100);
			if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') t = max(t, 10);
			if(c >= '0' && c <= '9') t = max(t, c - '0');
		}
		res += t;
		getchar();
	}
	cout << res;
	return 0;
}