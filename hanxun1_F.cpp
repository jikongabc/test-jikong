#include<iostream>
#define endl '\n';
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		if(s[0] != 'y' &&  s[0] != 'Y' || s[1] != 'e' && s[1] != 'E' || s[2] != 's' && s[2] != 'S'){
			cout << "NO" << endl;
		} 
		else cout << "YES" << endl;
	}
	return 0;
}