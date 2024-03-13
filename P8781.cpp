#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int maxn=max(2*(n-i),2*(i-1));
		cout<<maxn<<endl;
	}
	return 0;
}
