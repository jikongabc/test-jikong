#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
char ch[N][N];
bool st[N][N];
int n,m;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,1,-1,1,0,-1};
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a>=0 && b>=0 && a<n && b<m && ch[a][b]=='W' && !st[a][b]){
			st[a][b]=true;
			dfs(a,b);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++) cin>>ch[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ch[i][j]=='W' && !st[i][j]){
				dfs(i,j);
				ans++;
			}
		}		
	}
	cout<<ans;
	return 0;
}
