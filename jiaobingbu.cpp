#include<iostream>
using namespace std;
int a[105], b[105], cnt1[1005], cnt2[1005];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt1[x]++;
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		cnt2[x]++;
	}
	for(int i = 0; i <= 1000; i++){
		if(cnt1[i] && cnt2[i]) cout << i << ' ';
	}
	cout << endl;
	for(int i = 0; i <= 1000; i++){
		if(cnt1[i] || cnt2[i]) cout << i << ' ';
	}
	cout << endl;
	for(int i = 0; i <= 1000; i++){
		if(!cnt1[i] && cnt2[i]){
			cout << -1;
			return 0;
		}
	}
	for(int i = 0; i <= 1000; i++){
		if(cnt1[i] && !cnt2[i]) cout << i << ' ';
	}
	cout << endl;
	return 0;
}