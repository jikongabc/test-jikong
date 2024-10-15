#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int res = 0;
	while(n > 10){
		bool flag = false;
		for(int i = 2 ; i * i <= n; i ++){
			if(n % i == 0){
				flag = true;
				break;
			}
		}
		if(!flag) res++;
		int sum = 0;
		while(n){
			int t = n % 10;
			sum += t * t;
			n /= 10;
		}
		n = sum;
	}
	if(n == 1){
		cout <<"YES\n";
	}
	else cout <<"NO\n";
	cout << res << endl;
	return 0;
}
