//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<queue>
//using namespace std;
// 
//const int N = 1010;
// 
//char g[N][N];
// 
//bool st[N][N];
// 
//int px[4] = {-1,0,1,0};
//int py[4] = {0,1,0,-1};
// 
//void solve()
//{
//    int n,m; cin >> n >> m;
//    for(int i = 1 ; i <= n ; i ++)
//        for(int j = 1 ; j <= m ; j ++)
//             cin >> g[i][j];
//    queue<vector<int> > q;
//    q.push({0,0});
//    while(!q.empty())
//    {
//        auto t = q.front();
//        q.pop();
//        int a = t[0],b = t[1];
//        st[a][b] = 1;
//        for(int i = 0 ; i < 4 ; i ++)
//        {
//            int x = a + px[i]; int y = b + py[i];
//            if(st[x][y] || x < 0 || x > n + 1|| y < 0 || y > m + 1) continue;
//            if(g[x][y] != '*' && !st[x][y])
//            {
//                q.push({x,y});
//                st[x][y] = 1;
//            }
//            if(g[x][y] == '*') st[x][y] = 1;
//        }
//    }
//    for(int i = 1 ; i <= n ; i ++)
//    {
//        for(int j = 1; j <= m ; j ++)
//            if(st[i][j]) cout << ".";
//            else cout << g[i][j];
//        cout << "\n";
//    }
//}
// 
//int main()
//{
//    int t = 1;
//    while (t--)
//    {
//        solve();
//    }
//};

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int N=1005;
int n,m;
bool st[N][N];
char p[N][N];
queue<PII> q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(int x,int y){
	memset(st,false,sizeof st);
	q.push({x,y});
	st[x][y]=true;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(!st[a][b] && a>=0 && a<=n+1 && b>=0 && b<=m+1 ){
				if(p[a][b]!='*'){
					q.push({a,b});
					st[a][b]=true;
				}
				else st[a][b]=true;
			} 
			
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	bfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(st[i][j]) cout<<'.';
			else cout<<p[i][j];
		}
		cout<<endl;
	}
	return 0;
}
