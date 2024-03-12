#include<iostream>
#define int long long
const int N=200005;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,sum=0;
	int a[N],b[N];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i]*(b[n]-b[i]);
	}
	cout<<sum;
	return 0;
}
