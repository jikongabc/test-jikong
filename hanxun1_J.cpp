#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		int a[55];
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		if(a[0] == a[n - 1]){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << a[n - 1] << ' ';
		for(int i = 0; i < n - 1; i++){
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}