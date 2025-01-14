#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int a[105];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			int m;
			cin >> m;
			string s;
			cin >> s;
			for(int j = 0; j < m; j++){
				if(s[j] == 'U') a[i] = (a[i] - 1 + 10) % 10;
				else a[i] = (a[i] + 1) % 10;
			}
		}
		for(int i = 0; i < n; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}