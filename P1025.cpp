#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10;
int n,k;
int arr[N];
int ans=0;
void dfs(int x,int start,int sum){
	if(sum>n) return;
	if(x>k){
		if(sum==n){
			ans++;
		}
		return ;
	}
	for(int i=start;sum+i*(k-x+1)<=n;i++){
		arr[x]=i;
		dfs(x+1,i,sum+i);
	    arr[x]=0;
		
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
