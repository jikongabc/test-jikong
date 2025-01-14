#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		int a[300005];
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		if(a[0] > a[n - 1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}