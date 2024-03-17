#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=35;
typedef pair<int,int> PII;
queue<PII> q;
bool st[N][N];
int g[N][N];
int n;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void bfs(int x,int y){
	q.push({x,y});
	st[x][y]=1;
	while(!q.empty())
{	PII t=q.front();
	q.pop();
	for(int i=0;i<4;i++){
		int a=t.first+dx[i],b=t.second+dy[i];
	
		if(a>=0 && b>=0 && a<=n+1 && b<=n+1 && !st[a][b] && g[a][b]==0){
			st[a][b]=1;
			q.push({a,b});
		}
	}}
	return;
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	bfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==0 && !st[i][j]){
				g[i][j]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
