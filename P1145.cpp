//#include<iostream>
//using namespace std;
//int k,num1,num2,temp=2;
//void dfs(int start,int n){
//	if(num2==0){
//		cout<<n;
//		return;
//	}
//	while(temp>1  && num2>0){
//		temp=start+n-1;
//		if(temp>num1+num2) temp-=(num1+num2);
//		if(temp<=num1) num1--;
//		else num2--;
//		start=temp+1;
//	}
//	if(temp<=1) dfs(1,n+1);
//	return ;
//	
//}
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	cin>>k;
//	num1=k,num2=k;
//	dfs(1,2);
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int k,temp,m=2;
//	cin>>k;
//	int start=1,num1=k,num2=k;
//	while(1){
//		temp=start+m-1;
//		temp=temp%(num1+num2);
//		if(temp>num1){
//			num2--;
//		}
//		else num1--;
//		start=temp;
//		if(temp==1){
//			m++;
//			start=1;
//			num1=k;
//			num2=k;
//		} 
//		if(num2==0){
//			cout<<m;
//			break;
//		}	
//	}
//	return 0;
//}
