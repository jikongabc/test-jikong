#include<iostream>
using namespace std;
int main(){
	int n, m;
	string a;
	cin >> n >> m >> a;
	while(m--){
		char c, d;
		cin >> c >> d;
		for(int i = 0; i < n; i++){
			if(a[i] == c) a[i] = d;
		}
	}
	cout << a;
	return 0;
}