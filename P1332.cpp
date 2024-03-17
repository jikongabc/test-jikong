#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=510;
typedef pair<int,int> PII;
queue<PII> q;
int n,m,a,b;
int s[N][N];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
void bfs(){
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a>0 && b>0 && a<=n && b<=m && s[a][b]<0 ){
				s[a][b]=s[t.first][t.second]+1;
				q.push({a,b});
		}
	}
}
}
int main(){
	cin>>n>>m>>a>>b;
	memset(s,-1,sizeof s);
	while(a--){
		int x1,y1;
		cin>>x1>>y1;
		q.push({x1,y1});
		s[x1][y1]=0;
	}
	bfs();
	while(b--){
		int x2,y2;
		cin>>x2>>y2;
		cout<<s[x2][y2]<<endl;
	}
	return 0;
}
