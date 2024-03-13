#include<iostream>
#define int long long
using namespace std;
signed main(){
	int n,sum=0,num;
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp=i;
		while(temp!=0){
			num=temp%10;
			temp/=10;
			if(num==2||num==0||num==1||num==9){
				sum+=i;
				break;
			}
		}
		
	}
	cout<<sum;
	return 0;
}
