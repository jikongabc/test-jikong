#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
//#define int long long
using namespace std;
const int N=20;
int n;
int s[N],b[N];
int st[N];
int ans=0x3f3f3f3f;
void dfs(int x){
	bool temp=false;
	if(x>n){
		int sum1=1;
		int sum2=0;
		for(int i=1;i<=n;i++){
			if(st[i]==1){
				temp=true;
				sum1*=s[i];
				sum2+=b[i];
			}
		}
		if(temp){
			ans=min(ans,abs(sum1-sum2));
		}
		return;	
	}
	
	st[x]=1;
	dfs(x+1);
	st[x]=0;
	st[x]=2;
	dfs(x+1);
	st[x]=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>b[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
