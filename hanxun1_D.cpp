#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.size() - 1;
	while(s[n] == '0'){
		n--;
	}
	for(int i = 0; i <= n / 2; i++){
		if(s[i] != s[n - i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}