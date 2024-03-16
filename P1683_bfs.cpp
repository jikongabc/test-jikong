#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=25;
char ch[N][N];
typedef pair<int,int> PII;
int n,m;
int x1,y1;
int st[N][N];
queue<PII> q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x,int y){
	int count=0;
	memset(st,-1,sizeof st);
	q.push({x,y});
	st[x][y]=0;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a>0 && b>0 && a<=n && b<=m && ch[a][b]!='#' && st[a][b]<=0){
				q.push({a,b});
				st[a][b]=st[t.first][t.second]+1;
				count++;
			}
		}
	}
	return count;	
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
	int ans=bfs(x1,y1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(st[i][j]>=0){
//				ans++;
//			}
//		}
//	}
	cout<<ans;
	return 0;
}
