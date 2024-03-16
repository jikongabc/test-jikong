#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=26;
int n;
int ans=0;
int arr[N];
int y[]={6,2,5,5,4,5,6,3,7,6};
int col(int m){
	if(y[m]>0) return y[m];

		int sum1=0;
		while(m){
			sum1+=y[m%10];
			m/=10;
		}	
		return sum1;
	
}
void dfs(int x,int sum){
	if(sum>n) return;
	if(x>3){
		if(arr[1]+arr[2]==arr[3] && sum==n){
			ans++;
//			for(int i=1;i<=3;i++) cout<<arr[i]<<' ';
//			cout<<endl;
		}
		return;
		
	}
	for(int i=0;i<=1000;i++){
		arr[x]=i;
		dfs(x+1,sum+col(i));
		arr[x]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	n-=4;
	dfs(1,0);
	cout<<ans;
	return 0;
}
