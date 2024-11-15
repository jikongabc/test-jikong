#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
	int n;
	long long sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	int t = 0;
	while(a[t] % 2 == 0 && t < n){
		t++;
	}
	if(sum % 2 == 0)
		cout << sum;
	else cout << sum - a[t];
	return 0;
}