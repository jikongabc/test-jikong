#include<iostream>
#include<algorithm>
#include<cstring>
//#define int long long
using namespace std;
const int N=20;
int n;
int ans;
int arr[N];
int a[8955][N];
void dfs(int x,int sum){
	if(sum>n) return ;
	if(x>10){
		if(sum==n){
			ans++;
			for(int i=1;i<=10;i++){
				a[ans][i]=arr[i];
			}
		}
		return;
	}
	for(int i=1;i<=3;i++){
		arr[x]=i;
		dfs(x+1,sum+i);
		arr[x]=0;
	}
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n>30 || n<10) cout<<0;
	else{
		dfs(1,0);
		cout<<ans<<endl;
		for(int i=1;i<=ans;i++){
			for(int j=1;j<=10;j++){
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
	} 
	return 0;
}
