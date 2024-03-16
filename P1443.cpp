#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=410;
typedef pair<int,int> PII;
queue<PII> q;
int s[N][N];
int n,m;
int x1,y1;
int dx[]={2,2,1,1,-1,-1,-2,-2};
int dy[]={1,-1,2,-2,2,-2,1,-1};
int bfs(int x,int y){
	memset(s,-1,sizeof s);
	q.push({x,y});
	s[x][y]=0;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a>0 && b>0 && a<=n && b<=m && s[a][b]<=0){
				q.push({a,b});
				s[a][b]=s[t.first][t.second]+1;
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>x1>>y1;
	bfs(x1,y1);
	s[x1][y1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",s[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
