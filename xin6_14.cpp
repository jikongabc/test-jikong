#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int cnt[1000005];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++; 
	}
	int t = 0, tt = 0;
	int maxn = 0;
	for(int i = 1; i < 1000000; i++){
		if(cnt[i]){
			maxn = max(maxn, i);
			t++;
			tt += cnt[i];
		}
	}
	cout << t * 5 + 10 * maxn + tt;
	return 0;
}