#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string s[101];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1; j++){
			if(s[i][j] == '#' && s[i + 1][j] == '#' && s[i][j + 1] == '#' && s[i + 1][j + 1] == '#'){
				cout << "AC";
				return 0;
			}
		}
	}
	cout << "Abandon";
	return 0;
}