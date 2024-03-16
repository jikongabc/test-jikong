#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
const int N=410;
int n,m;
int s[N][N];
PII q[N*N];
int dx[]={2,2,1,1,-1,-1,-2,-2};
int dy[]={1,-1,2,-2,2,-2,1,-1};
void bfs(int x,int y){
	memset(s,-1,sizeof s);
	q[0] = {x,y};
	s[x][y]=0;
	int hh=0,tt=0;
	while(hh<=tt){
		PII t=q[hh++];
		for(int i=0;i<8;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1|| a>n|| b<1||b>m) continue;
			if(s[a][b]>=0) continue;
			s[a][b]=s[t.first][t.second]+1;
			q[++tt] = {a,b};
		}
	}	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x1,y1;
	cin>>n>>m>>x1>>y1;
	bfs(x1,y1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d",s[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
