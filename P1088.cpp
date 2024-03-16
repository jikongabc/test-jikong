#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const  int N=10005;
int n,m;
int mars[N];
bool st[N];
int arr[N];
int res=0;
void dfs(int x){
	if(res==m+1) return;
	if(x>n){
		res++;
		if(res==m+1){
			for(int i=1;i<=n;i++){
				cout<<arr[i]<<' ';
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!res){
			i=mars[x];
		}
		if(!st[i]){
			st[i]=1;
			arr[x]=i;
			dfs(x+1);
			st[i]=0;
			arr[x]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>mars[i];
	dfs(1);
	return 0;
}
