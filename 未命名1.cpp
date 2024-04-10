//#include<iostream>
//#include<cmath>
//using namespace std;
//typedef long long LL;
//int main(){
//	LL n=23333333;
////	for(int i=11666667;i<=n;i++){
////		for(int j=1;j<=i;j++){
////			sum-=(double)log2(i/n)*(double)(i/n*1.0);
////		}
////		for(int j=1;j<=n-i;j++){
////			sum-=(double)log2((n-i)/n)*(double)(n-i)*1.0/n;
////		}
////		if(sum==11625907.5798) cout<<n-i;
////	}
//
//	for(int i=0;i<=n;i++){
//		double x=(-1.0)*i/n*log2(1.0*i/n)*i;
//		double y=(-1.0)*(n-i)/n*log2(1.0*(n-i)/n)*(n-i);
//		if(x+y>=11625907.5798 &&x+y<=11625907.5799) cout<<i;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//typedef long long LL;
//int main(){
//  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//  const int N=1e4+10;
//  int t;
//  cin>>t;
//  int a[N],b[N];
//  int maxn=0;
//  for(int i=1;i<=t;i++){
//    cin>>a[i]>>b[i];
//    maxn=max(a[i],maxn);
//  }
//  int min_ans=0x3f3f3f3f;
//  int max_ans=0;
//  for(int i=1;i<=maxn;i++){
//    int temp=0;
//    for(int j=1;j<=t;j++){
//      if(a[j]/i!=b[j]){
//          temp=1;
//          break;
//      } 
//    }
//    if(!temp){
//min_ans=min(min_ans,i);
//max_ans=max(max_ans,i);
//    }
//  }
//  cout<<min_ans<<' '<<max_ans;
//  return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N=20;
//
//struct node{
//	int t,d,l;
//}p[N];
//
//bool cmp(node a,node b){
//	return a.t+a.d<b.t+b.d;
//}
//
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		int pd=0;
//		int n;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>p[i].t>>p[i].d>>p[i].l;
//		}
//		int temp=0;
//		sort(p+1,p+1+n,cmp);
//	for(int i=1;i<n;i++){
//		if(temp+p[i].l<=p[i+1].t+p[i+1].d){
//			temp+=p[i].l;
//		}
//		else{
//			pd=1;
//			break;
//		}
//	}
//	if(!pd) cout<<"YES\n";
//	else cout<<"NO\n";
//	}
//	return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<map>
//using namespace std;
//const int N=55;
//char p[N][N];
//bool st[N][N];
//int n,m;
//int dx[]={-1,0,1,0};
//int dy[]={0,1,0,-1};
//int dx1[]={1,1,1,0,0,-1,-1,-1};
//int dy1[]={0,1,-1,1,-1,0,1,-1};
//void dfs(int x,int y){
//	st[x][y]=1;
//	for(int i=0;i<4;i++){
//		int a=x+dx[i],b=y+dy[i];
//		if(a<=0 ||b<=0 || a>n || b>m) continue;
//		if(p[a][b]!='1') continue;
//		if(st[a][b]) continue;
//		dfs(a,b);
//	}
//	return;
//}
//
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		int ans=0;
//		cin>>n>>m;
//		memset(st,false,sizeof st);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cin>>p[i][j];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				if(p[i][j]=='1' && !st[i][j]){
//					dfs(i,j);
//					ans++;
//				}
//			}
//		}
//		cout<<ans<<'\n';
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//
//const int N=110;
//int dxx[]={-1,-1,0,1,1,1,0,-1},dyy[]={0,1,1,1,0,-1,-1,-1};
//int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
//char ma[N][N];
//int T,n,m,c;
//bool st[N][N];
//typedef pair<int,int> PII;
//
//void bbfs(int x,int y)
//{
//    c++;
//    queue<PII> q;
//    q.push({x,y});
//    st[x][y]=true;
//    while(q.size())
//    {
//        PII t=q.front();
//        q.pop();
//        for(int i=0;i<4;i++)
//        {
//            int nx=t.first+dx[i],ny=t.second+dy[i];
//            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=m+1&&ma[nx][ny]=='1'&&!st[nx][ny])
//            {
//                q.push({nx,ny});
//                st[nx][ny]=true;
//            }
//        }
//    }
//}
//
//void bfs(int x,int y)
//{
//    queue<PII> q;
//    q.push({x,y});
//    st[x][y]=true;
//    while(q.size())
//    {
//        PII t=q.front();
//        q.pop();
//        for(int i=0;i<8;i++)
//        {
//            int nx=t.first+dxx[i],ny=t.second+dyy[i];
//            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=m+1&&!st[nx][ny])
//            {
//                if(ma[nx][ny]=='1')bbfs(nx,ny);
//                else q.push({nx,ny}),st[nx][ny]=true;
//            }
//        }
//    }
//}
//
//void solve()
//{
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=m;j++)
//            cin>>ma[i][j];
//    bfs(0,0);
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>T;
//    while(T--)
//    {
//        c=0;
//        memset(st,0,sizeof st);
//        memset(ma,'0',sizeof ma);
//        solve();
//        cout<<c<<"\n";
//    }
//    return 0;
//}



//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//typedef long long LL;
//const int N=1e5+10;
//string s[N];
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>s[i];
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		int j=i+1;
//		while(s[i][s[i].size()-1]!=s[j][0]){
//			j++;
//		}
//		ans+=j-i-1;
//		i=j;
//	}
//	cout<<ans;
//	return 0;
//} 

//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//typedef long long LL;
//const int N=5e5+10;
//int k;
//string s;
//char a,b;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>k;
//	int ans=0;
//	cin>>s>>a>>b;
//	for(int i=0;i<=s.size()-k;i++){
//		if(s[i]==a){
//			for(int j=i+k-1;j<s.size();j++){
//				if(s[j]==b) ans++;
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}




//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef long long LL;
//const int N=5e5+10;
//const LL MAXN=0x3f3f3f3f;
//LL a[N];
//int n,k;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>n>>k;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=k;i++){
//		LL minn=MAXN;
//		int index=0;
//		for(int i=1;i<=n;i++){
//			if(a[i]<minn){
//				minn=a[i];
//				index=i;
//			} 
//		}
//		a[index]=MAXN;
//		int temp=index-1;
//		while(a[temp]==MAXN){
//			temp--;
//		}
//		if(temp>=1)
//		a[temp]+=minn;
//		temp=index+1;
//		while(a[temp]==MAXN){
//			temp++;
//		}
//		if(temp<=n)
//		 a[temp]+=minn;
//	}
//	for(int i=1;i<=n;i++){
//		if(a[i]!=MAXN) cout<<a[i]<<' ';
//	}
//	
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//using namespace std;
//int time[N][N];
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	
//	return 0;
//}



//#include<iostream>
//#include<cmath>
//using namespace std;
//typedef long long LL;
//int main(){
//  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//  const int N=1e4+10;
//  int t;
//  cin>>t;
//  int a[N],b[N];
//  int minn=0x3f3f3f3f;
//  int max_ans=0x3f3f3f3f;
//  int min_ans=0;
//  for(int i=1;i<=t;i++){
//    cin>>a[i]>>b[i];
//    int temp1=(double)a[i]*1.0/((double)b[i]*1.0+1)+1;
//    int temp2=(double)a[i]*1.0/((double)b[i]*1.0);
//    
//    min_ans=max(min_ans,temp1);
//    max_ans=min(max_ans,temp2);
//  }
//  cout<<min_ans<<' '<<max_ans;
//  return 0;
//}




#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long LL;
const int N=1e5+10;
string s[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=i+1;
		while(s[i][s[i].size()-1]!=s[j][0]){
			j++;
		}
		ans+=j-i-1;
		i=j;
	}
	cout<<ans;
	return 0;
} 






