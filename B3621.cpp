#include<iostream>
using namespace std;
int n,k;
int arr[10];
void dfs(int m){
	if(m>k){
		for(int i=1;i<=k;i++){
			cout<<arr[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
			arr[m]=i;
			dfs(m+1);
		}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k>>n;
	dfs(1);
	return 0;
}


