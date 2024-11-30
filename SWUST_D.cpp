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
const int N = 1010;
int n;
int a[N][N];
int r[N], c[N];
int x, y;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cin >> x >> y;
	for(int i = 1; i <= n; i++){
		r[i] = a[x][i];
	}
	for(int i = 1; i <= n; i++){
		c[i] = a[i][y];
		a[i][y] = r[i];
	}
	for(int i = 1; i <= n; i++){
		a[x][i] = c[i];
	}
	a[x][y] = (r[x] + c[y] + 1) / 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}