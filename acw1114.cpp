#include<iostream>
#include<cstring>
using namespace std;
const int N=10;
int n,k;
char ch[N][N];
bool st[N];
int ans=0;
void dfs(int x,int cnt){
	if(cnt==k){
		ans++;
		return ;
	}
	if(x==n) return;
	for(int i=0;i<n;i++){
		if(!st[i] && ch[x][i]=='#'){
			st[i]=true;
			dfs(x+1,cnt+1);
			st[i]=false;
		}
	}
	dfs(x+1,cnt);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>k,n!=-1 && k!=-1){
		ans=0;
		for(int i=0;i<n;i++) cin>>ch[i];
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
