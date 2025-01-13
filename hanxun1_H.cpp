#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		int a[1010];
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		if(sum > m) cout << m << endl;
		else cout << sum << endl;
	}
	return 0;
}