#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=1010;
typedef pair<int,int> PII;
queue<PII> q;
int n;
int x1,y1,x2,y2;
char ch[N][N];
int s[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int bfs(int x,int y){
	memset(s,-1,sizeof s);
	q.push({x,y});
	s[x][y]=0;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a>0 && b>0 && a<=n && b<=n && ch[a][b]!='1' && s[a][b]<=0){
				q.push({a,b});
				s[a][b]=s[t.first][t.second]+1;
				if(s[x2][y2]>0) return s[x2][y2];
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch[i][j];
		}
	}
	cin>>x1>>y1>>x2>>y2;
	int ans=bfs(x1,y1);
	cout<<ans;
	return 0;
}
