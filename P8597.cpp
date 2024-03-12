#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	char ch[1005];
	char ch1[1005];
	int count=0;
	cin>>ch>>ch1;
	for(int i=0;i<strlen(ch);i++){
		if(ch[i] !=ch1[i]){
			count++;
			if(ch[i+1]=='*') ch[i+1]='o';
			else ch[i+1]='*';
		}
	}
	cout<<count;
	return 0;
}
