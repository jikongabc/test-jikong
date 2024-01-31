#include<stdio.h>
int main(){
	int w;
	scanf("%d",&w);
	if(w%2==0 && w !=2){
		printf("YES");
	}
	else{
		printf("NO");
	}

	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int n,i,len,num;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char a[105];
		scanf("%s",&a);
		len=strlen(a);
		if(len>10){
			num=len-2;
			printf("%c%d%c\n",a[0],num,a[len-1]);
		}
		else{
			puts(a);
			printf("\n");
		}
		
	}
	return 0;
}

#include<stdio.h>
int main(){
	long long n,m,a,num1,num2;
	scanf("%lld%lld%lld",&n,&m,&a);
	if(n%a==0){
		num1=n/a;
	}
	else{
		num1=n/a+1;
	}
	if(m%a==0){
		num2=m/a;
	}
	else{
		num2=m/a+1;
	}
	printf("%lld",num1*num2);
	return 0;
}

#include<stdio.h>
int main(){
	int n,i,j,sum,num=0;
	int a[4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		sum=0;
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		for(j=0;j<=2;j++){
			if(a[j]==1){
				sum+=1;
			} 
		} 
		if(sum>=2){
			num+=1;
		}
	} 
	printf("%d",num);
	return 0;
}

#include<stdio.h>
int main(){
	int n,k,i,sum=0;
	int a[55];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(a[i]>=a[k-1] && a[i]>0) {
			sum+=1;
		}
	}
	printf("%d",sum);
	return 0;
}

#include<stdio.h>
int main(){
	int m,n,num;
	scanf("%d%d",&m,&n);
	num=m*n;
	printf("%d",num/2);
	return 0;
}


#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char a[5];
		scanf("%s",a);
		getchar();
			if(a[0]=='X' && a[1]=='+'&& a[2]=='+'|| a[0]=='+'&& a[1]=='+' && a[2]=='X'){
				sum+=1;
			}
			else{
				sum-=1;
			}
		}
		printf("%d",sum);
	
	return 0;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int i,j,num,sum=0;;
	int a[6][6]={ 0 };
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			scanf("%d",&a[i][j]);
		}	
	}
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			if(a[i][j]==1){
				sum=1;
				break;
			}
		}
		if(sum==1){
			break;
		}
}
	num=abs(i-3) + abs(j-3);
	printf("%d",num);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int i,j,num=0,sum=0;
	char a[105];
	char b[105];
	scanf("%s",a);
	getchar();
	scanf("%s",b);
	for(i=0;i<strlen(a);i++){
		if(a[i]>='a' && a[i]<='z'){
			a[i]-=32;
		}
		if(b[i]>='a' && b[i]<='z'){
			b[i]-=32;
		}
	}
//	for(i=0;i<strlen(a);i++){
//		for(j=0;j<strlen(a)-i;j++){
//			if(a[i]>a[j+1]){
//				a[strlen(a)+1]=a[i];
//				a[i]=a[j];
//				a[j]= a[strlen(a)+1];
//				if(b[i]>b[j+1]){
//				b[strlen(a)+1]=b[i];
//				b[i]=b[j];
//				b[j]= b[strlen(a)+1];
//			}
//			}
//		}
//	}
	for(i=0;i<strlen(a);i++){
		if(a[i]==b[i]){
			continue;
		}
		if(a[i]>b[i]){
			printf("1");
			break;
		}
		if(a[i]<b[i]){
			printf("-1");
			break;
		}
	}
	if(i>=strlen(a)){
		printf("0");
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int i;
	char a[105];
	scanf("%s",a);
	for(i=1;i<=strlen(a);i++){
		if(a[i-1]=='A' || a[i-1]=='a' || a[i-1]=='O' || a[i-1]=='o' ||a[i-1]=='Y' || a[i-1]=='y' || a[i-1]=='E' || a[i-1]=='e' || a[i-1]=='U' || a[i-1]=='u' ||a[i-1]== 'I' || a[i-1]=='i' ){
			a[i-1]='*';
		}
	}
		for(i=1;i<=strlen(a);i++){
			if(a[i-1]>='A' && a[i-1]<='Z'){
				a[i-1]+=32;
			}
		}
		for(i=1;i<=strlen(a);i++){
			if(a[i-1] !='*'){
				printf(".");
				printf("%c",a[i-1]);
			}
		}
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int i,j;
	int num=0;
	char a[105];
	int b[105];
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		if(a[i]>=48 && a[i]<=57){
			b[num]=a[i];
			num++;
		}	
	}
	sort(b,b+num);
	num=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]>=48 && a[i]<=57){
			a[i]=b[num];
			num++;
		}
	}
	puts(a);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	char a[1005];
	scanf("%s",a);
	if(a[0]>='a' && a[0]<='z'){
		a[0]-=32;
	}
	puts(a);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int i,j,sum=0;
	char a[105];
	scanf("%s",&a);
	for(i=0;i<strlen(a)-1;i++){
		for(j=i+1;j<strlen(a);j++){
			if(a[i]==a[j]){
				a[j]='*';
			}
		}
	}
	for(i=0;i<strlen(a);i++){
		if(a[i] !='*'){
			sum+=1; 
		}
	} 
	if(sum%2==0){
		printf("CHAT WITH HER!");
	}
	else{
		printf("IGNORE HIM!");
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,sum=0;
	char a[55];
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;i++){
		if(a[i]==a[i+1]){
			sum+=1; 
		}
	}
	printf("%d",sum);
	return 0;
}

#include<stdio.h>
int main(){
	int n,i,sum1=0,sum2=0,sum3=0;
	int a[105];
	int b[105];
	int c[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		sum1+=a[i];
		sum2+=b[i];
		sum3+=c[i];
	}
	if(sum1==0 && sum2==0 && sum3==0){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}

#include<stdio.h>
int main(){
	int i;
	long long k,n,w,num,sum=0;
	scanf("%lld%lld%lld",&k,&n,&w);
	for(i=1;i<=w;i++){
		num=i*k;
		sum+=num;
	}
	if(sum-n>0){
		printf("%lld",sum-n);
	}
	else{
		printf("0");
	}
	return 0;
}


#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%5==0){
		printf("%d",n/5);
	}
	else{
		printf("%d",n/5+1);
	}
	return 0;
}


#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%5==0){
		printf("%d",n/5);
	}
	else{
		printf("%d",n/5+1);
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int i,num1=0,num2=0; 
	char a[105];
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		if(a[i]>='A' && a[i]<='Z'){
			num1+=1;
		}
		if(a[i]>='a' && a[i]<='z'){
			num2+=1;
		}
	}
	if(num1>num2){
		for(i=0;i<strlen(a);i++){
			if(a[i]>='a' && a[i]<='z'){
				a[i]-=32;
			}
		}
	}
	else{
		for(i=0;i<strlen(a);i++){
			if(a[i]>='A'&& a[i]<='Z'){
				a[i]+=32;
			}
		}
	}
	puts(a);
	return 0;
}

#include<stdio.h>
int main(){
	int i;
	long long k,n,w,num,sum=0;
	scanf("%lld%lld%lld",&k,&n,&w);
	for(i=1;i<=w;i++){
		num=i*k;
		sum+=num;
	}
	if(sum-n>0){
		printf("%lld",sum-n);
	}
	else{
		printf("0");
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	int i,j,sum=0,num=0;
	char a[105];
	scanf("%s",a);
	for(i=0;i<strlen(a);i++){
		for(j=i+1;j<=strlen(a);j++){
			num+=1; 
			if(num>sum){
				sum=num;
			}
			if(a[i] !=a[j] ||sum>=7){
				break; 
			}
			
		}
		num=0;
		if(sum>=7){
				break;
		}
	}
	if(sum>=7){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
