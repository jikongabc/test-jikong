#include<iostream>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],cnt[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,ans=0;
	cnt[0]=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(a[i]%k==0) ans++;
		b[i]=b[i-1]+a[i];
		cnt[b[i]%k]++;
	}
	for(int i=0;i<k;i++){
		if(cnt[i]){
			ans+=cnt[i]*(cnt[i]-1)/2;
		}
	}
//	for(int i=1;i<=n-1;i++){
//		for(int j=i+1;j<=n;j++){
//			if((b[j]-b[i-1])%k==0) ans++;
//		}
//	}
	cout<<ans;
	return 0;
}
