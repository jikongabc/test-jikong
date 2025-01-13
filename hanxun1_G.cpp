#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
	int n;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	int maxn = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			cnt++;
		}
		if(s[i] == ' ' || i == n - 1){
			maxn = max(maxn, cnt);
			cnt = 0;
		}
	}
	cout << maxn;
	return 0;
}