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
const int N = 505;
int n;
int a[N][N];
int b[N][N];
int c[N][N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			b[i][j] = abs(a[i][j] - a[j][i]);
			if(b[i][j] & 1 || b[i][j] == 0){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) cout << a[i][j] << ' ';
			else if(a[i][j] > a[j][i]) c[i][j] = a[i][j] - b[i][j] / 2, cout << a[i][j] - b[i][j] / 2 << ' ';
			else if(a[i][j] < a[j][i]) c[i][j] = a[i][j] + b[i][j] / 2, cout << a[i][j] + b[i][j] / 2 << ' ';
		}
		cout << endl;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) cout << 0 << ' ';
			else cout << a[i][j] - c[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}