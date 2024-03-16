#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=25;
int n,m;
int x1,y1;
char ch[N][N];
int ans=0;
bool st[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a>0 && b>0 && a<=n && b<=m && ch[a][b]!='#'&& !st[a][b]){
			st[a][b]=true;
			ans++;
			dfs(a,b);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
			if(ch[i][j]=='@'){
				x1=i;
				y1=j;
			}
		}
	}
	dfs(x1,y1);
	cout<<ans;
	return 0;
}
