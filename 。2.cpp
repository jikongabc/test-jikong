#include<iostream>
using namespace std;
int main(){
	int l, r, k;
	cin >> l >> r >> k;
	int sum = 0;
	for(int i = l; i <= r; i++){
		int cnt = 0;
		bool st[100] = {0};
		int num = i;
		while(num){
			int t = num % 10;
			if(!st[t]){
				st[t] = 1;
				cnt++;
			}
			num /= 10;
		}
		if(cnt <= k) sum += i;
	}
	cout << sum;
	return 0;
}