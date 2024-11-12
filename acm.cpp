#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag[105];
int ans[105];
int main(){
	int n, m;
	cin >> n >> m;
	int res = 0;
	int cnt = 0;
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		if(!flag[a]){
			if(c == 1){
				flag[a] = 1;
				res += b;
				cnt++;
			}
			else ans[a] += 20;
		}
	}
	for(int i = 1; i <= n; i++){
		if(flag[i]) res += ans[i];
	}
	cout << cnt << ' ' << res;
	return 0;
}