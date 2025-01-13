#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	int T;
	cin >> T;
	// int cnt = 0;
	while(T--){
		// cnt++;
		// cout << cnt << ":";
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		char g[55][55];
		bool flag = false;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> g[i][j];
				if(g[i][j] == 'B') flag = true;
			}
		}
		if(!flag){
			cout << -1 << endl;
			continue;
		}
		if(g[r][c] == 'B'){
			cout << 0 << endl;
			continue;
		}
		flag = false;
		for(int i = 1; i <= n; i++){
			if(g[i][c] == 'B'){
				cout << 1 << endl;
				flag = true;
				break;
			}
		}
		for(int i = 1; i <= m; i++){
			if(g[r][i] == 'B'){
				if(!flag) cout << 1 << endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout << 2 << endl;
	}
	return 0;
}