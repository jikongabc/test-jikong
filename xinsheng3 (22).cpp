#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int cnt[N];
int n, k;
int res;
int pos;

int mex(int l, int r){
	memset(cnt, 0, sizeof cnt);
	for(int i = l; i <= r; i++){
		cnt[a[i]]++;
	}
	int t = 0;
	while(cnt[t]){
		t++;
	}
	return t;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n - k + 1; i++){
		int tmp = mex(i, i + k - 1);
		if(tmp > res){
			res = tmp;
			pos = i;
		}
	}
	cout << res << endl;
	int l = pos, r = pos + k - 1;
	int cnt = 0;
	for(int i = l; i <= (l + r) / 2; i++){
		if(a[i] != a[r - i]){
			cnt++;
		}
	}
	if(cnt == 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
