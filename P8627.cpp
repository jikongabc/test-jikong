#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	m=n;
	while(m>=3){
		n+=m/3;
		m=m%3+m/3;
	}
	cout<<n;
	return 0;
}
