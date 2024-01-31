//#include<stdio.h>
//#include<math.h>
//int main(){
//	long long num;
//	num=pow(2,2023);
//	printf("%lld",num%1000);
//}


//#include<stdio.h>
//#include<string.h>
//int main(){
//	int i;
//	char a[105];
//	scanf("%s",a);
//	for(i=strlen(a)-1;i>=0;i--){
//		if(a[i]=='a'|| a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'){
//			break;
//		}
//	}
//	printf("%c",a[i]);
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	long long n,num,num1,sum=1;
//	int i;
//	scanf("%lld",&n);
//	while(n>=10){
//		num1=n;
//	while(num1 >0){
//		num=num1%10;
//		num1=num1/10;
//		if(num !=0){
//			sum *=num;
//		}
//	}
//	printf("%lld\n",sum);
//	n=sum;
//	sum=1;
//	}
//	
//	
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n,m1,m2;
//	scanf("%d",&n);
//	m1=n/100000;
//	m2=n%100000;
//	printf("%d%d",m2,m1);
//	
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	long long n,k,sum=0,num;
//	int i,j;
//	long long a[105];
//	scanf("%lld%lld",&n,&k);
//	for(i=0;i<n;i++){
//		scanf("%lld",&a[i]);
//	}
//	for(i=0;i<n-k;i++){
//		num=0;
//		for(j=0;j<k;j++){
//			num+=a[i+j];
//		
//		if(num>sum){
//		sum=num;
//	}
//}
//}
//	printf("%lld",sum);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int i,n,j,num=0;
//	int a[40]={0};
//	int b[40]={0};
//	for(i=0;i<36;i++){
//		scanf("%d",&a[i]);
//	}
//	for(i=0;i<36;i++){
//		for(j=2;j<a[i];j++){
//			if(a[i]% j==0){
//				b[i]+=1;
//			}
//		}	
//	}
//	for(i=0;i<n;i++){
//		if(b[i]>num){
//			num=i;
//		}
//	}
//	printf("%d",a[i]);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//int main(){
//	int i,j,sum=0;
//	char a[35][45];
//	for(i=1;i<=30;i++){
//		for(j=1;j<=40;j++){
//			scanf("%c",&a[i][j]);
//		}
//		getchar();
//	}
//	a[1][1]='2';
//	for(i=1;i<=30;i++){
//		for(j=1;j<=40;j++){
//			if(a[i][j]=='2'&& a[i-1][j]=='0'){
//				a[i-1][j]='2';
//			}
//			if(a[i][j]=='2'&& a[i+1][j]=='0'){
//				a[i+1][j]='2';
//			}
//			if(a[i][j]=='2'&& a[i][j-1]=='0'){
//				a[i][j-1]='2';
//			}
//			if(a[i][j]=='2'&& a[i][j+1]=='0'){
//				a[i][j+1]='2';
//			}
//		}
//	}
//	for(i=1;i<=30;i++){
//		for(j=1;j<=40;j++){
//			if(a[i][j]=='2'){
//				sum+=1;
//			}
//		}
//	}
//	printf("%d",sum);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n,m,i,j,k,r,c;
//	long long num,sum=0;
//	long long a[1005][1005];
//	scanf("%d%d",&n,&m);
//	for(i=0;i<n;i++){
//		for(j=0;j<m;j++){
//			scanf("%lld",&a[i][j]);
//		}
//	}
//	scanf("%d%d",&r,&c);
//	long long b[1005][1005]={0};
//	b[r][c]=1;
//	for(i=0;i<n;i++){
//		for(j=0;j<m;j++){
//			if(b[i][j]==1){
//				if(a[i-1][j]<a[i][j]){
//					num=a[i-1][j];
//				}
//				else{
//					num=a[i][j];
//				}
//				for(k=2;k<=num;k++){
//					if(a[i][j]%k==0 && a[i-1][j]%k==0){
//						b[i-1][j]=1;
//					}	
//				}
//				if(a[i+1][j]<a[i][j]){
//					num=a[i+1][j];
//				}
//				else{
//					num=a[i][j];
//				}
//				for(k=2;k<=num;k++){
//					if(a[i][j]%k==0 && a[i+1][j]%k==0){
//						b[i+1][j]=1;
//					}	
//				}
//				if(a[i][j-1]<a[i][j]){
//					num=a[i][j-1];
//				}
//				else{
//					num=a[i][j];
//				}
//				for(k=2;k<=num;k++){
//					if(a[i][j]%k==0 && a[i][j-1]%k==0){
//						b[i][j-1]=1;
//					}	
//				}
//				if(a[i][j+1]<a[i][j]){
//					num=a[i][j+1];
//				}
//				else{
//					num=a[i][j];
//				}
//				for(k=2;k<=num;k++){
//					if(a[i][j]%k==0 && a[i][j+1]%k==0){
//						b[i][j+1]=1;
//					}	
//				}			
//			}
//			
//		}
//	}
//	for(i=0;i<n;i++){
//		for(j=0;j<m;j++){
//			if(b[i][j]==1){
//				sum+=1;
//			}
//		}
//	}
//	printf("%lld",sum);
//	return 0;
//}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int>PII;
const int N=1e5+5;
int n,m;
int a[1005][1005];
bool dis[1005][1005];

int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};

void bfs(int x,int y){
	queue<PII>q;
	q.push({x,y});
	dis[x][y]=1;
	while(!q.empty()){
		PII t=q.front();
		q.pop();
		
		for(int i=0;i<4;++i){
			int ix=t.first+dx[i],iy=t.second+dy[i];
			if(ix&&iy&&ix<=n&&iy<=m&&dis[ix][iy]==0&&__gcd(a[t.first][t.second],a[ix][iy])^1){
				dis[ix][iy]=1;
				q.push({ix,iy});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(dis,0,sizeof dis);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	int sx,sy;
	cin>>sx>>sy;
	bfs(sx,sy);
	
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			ans+=dis[i][j];
		}
	}
	cout<<ans;
	return 0;
}


