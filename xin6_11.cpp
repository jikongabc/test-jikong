#include<iostream>
#include<cstring>
#include<string>
using namespace std;

bool is_prime(int x){
	if(x == 1 || x == 0) return false;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int i = 1;
	int cnt = 0;
	while(cnt < n){
		if(is_prime(i)) cnt++;
		i++;
	}
	cout << i - 1;
	return 0;
}
