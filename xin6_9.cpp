#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[1010], b[1010];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] > a[i]) b[i]++;
		}
	}
	for(int i = 0; i < n; i++) cout << b[i] << ' ';
	return 0;
}