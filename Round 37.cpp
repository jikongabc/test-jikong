//#include<iostream>
//using namespace std;
//int main(){
//    int a,b;
//    cin>>a>>b;
//    if(a+b<10) cout<<"Yes";
//    else cout<<"No";
//    return 0;
//}


//#include<iostream>
//#include<algorithm>
//#define int long long
//using namespace std;
//signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n,x;
//	cin>>n>>x;
//	int a[100005];
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	sort(a,a+n);
//	int i;
//	for(i=0;i<n;i++){
//		if(a[i]>n) break;
//	}
//	cout<<i<<' '<<x-i;
//	
//	return 0;
//}



//#include<iostream>
//#include<cstring>
//#define int long long
//using namespace std;
//signed main(){
//    int n,i;
//    cin>>n;
//    if(n%495==0) cout<<-1;
//    else{
//        i=0;
//    while(n%495!=0){
//        i+=5;
//        int temp=i;
//        for(int j=0;j<temp/10;j++){
//            n*=10;
//        }
//        n+i;
//        
//    }
//    }
//    cout<<i;
//    
//    return 0;
//}
////495
////990
////1485
////1980
////2475
////2970
////3465
////3960
////4455
////4950
////5445
////5940
////6435
////6930
////7425
////7920



//#include<iostream>
//#include<cstring>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	string s;
//	char minn='z';
//	for(int i=0;i<s.size();i++){
//		minn=min(minn,s[i]);
//	}
//	cout<<minn;
//	return 0;
//}


#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=1005;
int n,m;
char ch[N][N];
int x1,y1,x2,y2;
int  st[N][N];
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,-1};
queue<PII> q;
int bfs(int x,int y){
	q.push({x,y});
	st[x][y]=0;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
				
				if(a>=0 && a<n && b>=0 && b<m && ch[a][b]!='#' && st[a][b]<=0){
					q.push({a,b});
					st[a][b]=st[t.first][t.second]+1;
				}
				if(a==x2 && b==y2) return st[x2][y2];
				}
	}
	return -1;	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(st,-1,sizeof st);
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(ch[i][j]=='S'){
					x1=i;
					y1=j;
				}
				if(ch[i][j]=='T'){
					x2=i;
					y2=j;
				}
			}
		}
		int ans=bfs(x1,y1);	
		cout<<ans<<endl;
	}
	return 0;
}
