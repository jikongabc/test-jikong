#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		int n = s.size();
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; i++){
			if(s[i] >= 'a' && s[i] <= 'z') cnt1++;
			else cnt2++;
		}
		if(cnt1 < cnt2){
			for(int i = 0; i < n; i++){
				if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
			}
		}
		else{
			for(int i = 0; i < n; i++){
				if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
			}
		}
		cout << s << endl;
	}
	return 0;
}