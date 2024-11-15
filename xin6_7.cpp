#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool is_prime(int x){
	if(x == 1 || x == 0) return false;
	for(int j = 2; j * j <= x; j++){
		if(x % j == 0) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for(int i = n; i <= m; i++){
		if(!is_prime(i)){
			cout << i << endl;
			cnt++;
		}
	}
	if(cnt == 0) cout << "None.";
	return 0;
}