#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<bitset>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e2 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
char p[N][N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> p[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(p[i][j] == '!'){
				p[i][j] = '@';
				for(int k = 0; k < 4; k++){
					int a = i + dx[k], b = j + dy[k];
					if(a < 0 || b < 0 || a >= n || b >= m) continue;
					if(p[a][b] >= '1' && p[a][b] <= '9') p[a][b]++;
					else if(p[a][b] == '&') p[a][b] = '#';
					else if(p[a][b] == '#') p[a][b] = '1';
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << p[i][j];
		}
		cout << endl;
	}
	return 0;
}