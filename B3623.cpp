#include<iostream>
using namespace std;
int n,k;
int arr[10];
bool st[10];
void dfs(int m){
	if(m>k){
		for(int i=1;i<=k;i++){
			cout<<arr[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			arr[m]=i;
			st[i]=1;
			dfs(m+1);
			st[i]=0;
		}
	}
	return;
}
int main(){
	cin>>n>>k;
	dfs(1);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	return 0;
}


