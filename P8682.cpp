#include<iostream>
#include<algorithm>
#define int long long
const int N=100005;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,i,j;
	int a[N];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	if(n==1) cout<<1;
	if(a[0]==a[n-1]) cout<<n;
	else{
		for(i=a[1];i>=1;i--){
				int temp=a[1]%i;
				for(j=1;j<n;j++){
					if(a[j]%i!=temp){
						break;
					}
				}
				if(j==n) break;
			}
		//	cout<<i<<endl;
			cout<<(a[n-1]-a[0])/i+1;
	}
	
	return 0;
}
