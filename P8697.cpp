#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	char a[1005],b[1005];
	string a,b;
	cin>>a>>b;
	int count=0;
	for(int i=0,j=0;i<a.size() && j<b.size();i++){
		if(a[i]==b[j]){
			j++;
			count++;
		}
	}
	cout<<count;
}


