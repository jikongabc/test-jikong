#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[100005], b[100005];
int main(){
	int n, x;
	int t = 0;
	int res = 0;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		if(b[i] == 1){
			t += a[i];
		}
		else{
			if(t >= a[i]){
				t -= a[i];
			}
			else{
				while(t < a[i]){
					t += x;
					res ++;
				}
				t -= a[i];
			}
		}
	}
	cout << res;
	return 0;
}