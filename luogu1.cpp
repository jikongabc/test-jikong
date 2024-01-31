//#include<stdio.h>
//int main(){
//	double a;
//	scanf("%lf",&a);
//	printf("%.2lf",a);
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	int a;
//	scanf("%d",&a);
//	printf("%03d",a);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	if(n %2==0){
//		printf("even");
//	}
//	else{
//		printf("odd");
//	}
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	long long m;
//	int k,i,num,sum=0;
//	scanf("%lld%d",&m,&k);
//	while(m !=0){
//		num=m%10;
//		m=m/10;
//		if(num==3){
//			sum+=1;
//		}
//	}
//	if(sum==k){
//		printf("YES");
//	}
//	else{
//		printf("NO");
//	}
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	int n,k,i;
//	double sum=0;
//	scanf("%d",&k);
//	for(i=1;sum<=k;i++){
//		sum+=1.0/i;	
//	}
//	printf("%d",i-1);
//	
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int l,r,i,num,num2,sum=0;
//	scanf("%d%d",&l,&r);
//	for(i=l;i<=r;i++){
//		num=i;
//		while(num!=0){
//			num2=num % 10;
//			num= num / 10;
//			if(num2==2){
//				sum+=1;
//			}
//		}
//	}
//	printf("%d",sum);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int a,b;
//	scanf("%d%d",&a,&b);
//	printf("%d",a+b);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	double c,f;
//	scanf("%lf",&f);
//	c=5*(f-32)/9.0;
//	printf("%.5lf",c);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int a,b,c,sum;
//	scanf("%d%d%d",&a,&b,&c);
//	if(a>b){
//		sum=a;
//	}
//	else{
//		sum=b;
//	}
//	if(sum>c){
//		printf("%d",sum);
//	}
//	else{
//		printf("%d",c);
//	}
//    return 0;
//}


//#include<stdio.h>
//int main(){
//	int a,b;
//	double r;
//	scanf("%d%d",&a,&b);
//	r=1.0/(1.0/a+1.0/b);
//	printf("%.2lf",r);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int n,num,sum=0;
//	scanf("%d",&n);
//	while(n !=0){
//		num=n%10;
//		n=n/10;
//		sum+=1;
//	}
//	if(sum==2){
//		printf("1");
//	}
//	else{
//		printf("0");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int a[100];
//	a[0]=1;
//	a[1]=1;
//	int n,i,b,j;
//	scanf("%d",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&b);
//		for(j=2;j<b;j++){
//			a[j]=a[j-1]+a[j-2];
//		}
//		printf("%d\n",a[b-1]);
//	}
//	return 0;
//}


