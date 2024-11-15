#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[50005];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--){
		if(a[i] != 0) cout << a[i] << ' ';
	}
	return 0;
}