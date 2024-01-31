//#include<stdio.h>
//int main(){
//	int t,i,n;
//	scanf("%d",&t);
//	for(i=0;i<t;i++){
//		scanf("%d",&n);
//		if(n%3==0){
//			printf("Second\n");
//		}
//		else{
//			printf("First\n");
//		}
//		
//	}
//	return 0;
//}


//#include<iostream>
//#include<math.h>
//using namespace std;
//int main(){
//	int n,i,sum1;
//	double sum=0,num,x,y,num1;
//	cin >>n;
//	for(i=0;i<n;i++){
//		cin >> x >> y >>num;
//		num1=sqrt(x*x+y*y);
//		sum+=num1*2.0/50.0;
//		sum+=num*1.5;
//	}
//	sum1=sum;
//	if(sum !=sum1){
//		sum1+=1;
//	}
//	cout<<sum1;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int m,n,i,sum=0;
//	int a[105];
//	cin>>m>>n;
//	for(i=0;i<n;i++){
//		cin>>a[i];
//	}
//	for(i=0;i<n;i++){
//		if(m-a[i]>=0){
//			m-=a[i];
//			sum+=1;
//		}
//	}
//	cout<< n-sum;
//}


//#include<iostream>
//using namespace std;
//int main(){
//	int n,t,i,num,sum=0;
//	cin>>n>>t;
//	for(i=0;i<n;i++){
//		cin>>num;
//		if(num>=t){
//			sum+=1;
//		}
//	}
//	cout<<sum;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int n,i,num,a,b,c,d,sum=0;
//	cin>>n;
//	for(i=0;i<n;i++){
//		cin>>num;
//		a=num%10;
//		num/=10;
//		b=num%10;
//		num/=10;
//		c=num%10;
//		d=num/10;
//		if(a-b-c-d>0){
//			sum+=1;
//		}	
//	}
//	cout<<sum;
//	return 0;
//}

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int main(){
//	int t,i,m,a=1;
//	long long x,k,num,sum=1;
//	cin>>t;
//	for(i=0;i<t;i++){
//		cin>>x>>k;
//		do{
//			num=x;
//			sum=0;
//			while(num>0){
//				sum+=num%10;
//				num/=10;
//			}
//			x++;
//		}
//		while(sum % k !=0 ); 
//		
//		cout<<x-1<<'\n';
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main(){
//	int t,i,j,k,n,x,num1,num2,num3=0,num;
//	cin>>t;
//	for(i=0;i<t;i++){
//		cin>>n>>x;
//		int a[55]={0};
//		for(j=0;j<n;j++){
//			cin>>a[j];
//		}
//		num1=2 * (x- a[n-1]);
//		num2=a[0];
//		for(j=0;j<n-1;j++){
//			if(num3<a[j+1]-a[j]){
//				num3=a[j+1]-a[j];
//			}
//		}
//		if(num2>num1){
//			num=num2;
//		}
//		else{
//			num=num1;
//		}
//		if(num<num3){
//			num=num3;
//		}
//		
//		cout <<num<<"\n";
//	}
//	
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int t,i,j,n,k,num;
//	int a[105];
//	cin>>t;
//	for(i=0;i<t;i++){
//		num=0;
//		cin>>n>>k;	
//		for(j=0;j<n;j++){
//			cin>>a[j];
//			if(a[j]==k){
//				num=1;
//			}
//		}
//		if(num==1){
//			cout<<"YES\n";
//		}
//		else{
//			cout<<"NO\n";
//		}
//	}
//	
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main(){
//	int t,i,j,n,k,m,sum;
//	int a[105];
//	int b[105];
//	cin>>t;
//	for(i=0;i<t;i++){
//		sum=0;
//		cin>>n>>k;
//		for(j=0;j<n;j++){
//			cin>>a[j];
//			b[j]=a[j];
//		}
//	sort(a,a+n,greater<int>());
//	for(j=0;j<n;j++){
//		if(a[j]!=b[j]){
//			sum=1;
//		}
//	}
//	if( k!=1){
//		cout<< "YES";
//	}
//	else{
//		if(sum==0){
//			cout<<"NO";
//		}
//		else{
//			cout<<"YES";
//		}
//	}
//}
//	return 0;
//}

#include<iostream>
using namespace std;
int main(){
	int t,i,n,j;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		int a[105];
		int b[105];
		int sum=0;
		cin>>a[0]>>b[0];
		for(j=1;j<n;j++){
			cin>>a[j]>>b[j];
			if(b[j]<b[0]){
				a[j]=0;
			}	
		}
		for(j=1;j<n;j++){
			if(a[j] >sum){
				sum=a[j];
			}
		}
		if(sum<a[0]){
			 cout<<sum+1 <<"\n";
		}
		else{
			cout<<"-1\n";
		}
		
	}
	return 0;
}








