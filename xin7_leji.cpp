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
string p[N];
int n, m;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		p[i] = "*" + p[i];
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				if(p[i][j] == p[k][m - i]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}