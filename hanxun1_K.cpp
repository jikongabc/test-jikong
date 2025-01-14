#include <iostream>
#define endl '\n'
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		string s;
		cin >> n >> s;
		int t = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '(') t++;
			else{
				t--;
				if(t < 0){
					cnt++;
					t++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}