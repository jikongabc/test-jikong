//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//#include<map>
//#include<set>
//#include<vector>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	if(n<3) cout<<-1;
//	else {
//		for(int i=0;i<n-3;i++) cout<<'A';
//		cout<<"CUC";
//	}
//	
//	return 0;
//}



//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<cstring>
//#include<map>
//#include<set>
//#include<vector>
//#define int long long
//using namespace std;
//const int N=2e5+10;
//int a[N],b[N],c[N];
//signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		b[i]=b[i-1]+a[i];
//	}
//	for(int i=1;i<=n;i++){
//		c[i]=c[i-1]+a[n-i+1];
//	}
//	for(int i=1;i<=n;i++){
//		int num1,num2;
//		int maxn=b[i];
//		for(int j=i;j<=n;j++){
////			cout<<b[j]<<' ';
//			if(b[j]>=maxn) num2=j;
//		}
//		int maxn1=c[i];
////		cout<<endl;
//		for(int j=n-i+1;j<=n;j++){
////			cout<<c[j]<<' ';
//			if(c[j]>=maxn1) num1=n-j+1;
//		}
////		cout<<endl;
//		cout<<b[num2]-b[num1-1]<<' ';
////		cout<<endl;
//	}
//	return 0;
//}




//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//#define int long long
//int a[2000][2000];
//using namespace std;
//signed main(){
//	int n,m,k;
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>n>>m>>k;
//	if(n==1 || m==1) cout<<-1;
//	else if(k>(m-1)*(n-1)) cout<<-1;
//	else{
//		a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=1;
//		k--;
//		int i=2,u=1;
//		while(k>0){
//			a[0][i]=1;
//			a[u][i]=1;
//			a[u][i-1]=1;
//			i++;
//			k--;
//			if(i==m){
//				i=1;
//				u++;
//			}
//		}
//		for(int j=0;j<n;j++){
//				for(int l=0;l<m;l++){
//					cout<<a[j][l];
//				}
//				cout<<endl;
//			}
//	}
//	return 0;
//}



