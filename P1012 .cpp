#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
bool cmp(const string&a,const string&b){
	return a+b>b+a;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string ch[25];
	for(int i=0;i<n;i++){
		cin>>ch[i];
	}
	sort(ch,ch+n,cmp);
	for(int i=0;i<n;i++){
		cout<<ch[i];
	}	
	return 0;
}
