#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n, m;
string s[105];
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] >= 'a' && s[i][j] <= 'z') s[i][j] -= 32;
			else s[i][j] += 32;
			cout << s[i][j];
		}
		cout << endl;
	}
	return 0;
}