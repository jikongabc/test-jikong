#include<iostream>
using namespace std;
int n,k=2;
char arr[10];
void dfs(int m){
	if(m>n){
		for(int i=1;i<=n;i++){
			cout<<arr[i];
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=2;i++){
		if(i==1) arr[m]='N';
		else arr[m]='Y';
		dfs(m+1);
	}
	return;
}
int main(){
	cin>>n;
	dfs(1);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	return 0;
}


