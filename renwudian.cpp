//#include<stdio.h>
//int main(){
//	int a,b;
//	char ch;
//	scanf("%d%c%d",&a,&ch,&b);
//	switch(ch){
//		case '+':
//			printf("=%d",a+b);
//			break;
//		case '-':
//			printf("=%d",a-b);
//			break;
//		case '*':
//			printf("=%d",a*b);
//			break;
//		case '/':
//			printf("=%d",a/b);
//	}
//	return 0;
//} 


//#include<stdio.h>
//#include<string.h>
//int main(){
//	int i,letter=0,blank=0,digit=0,other=0;
//	char ch;
//	for(i=0;i<15;i++){
//		ch=getchar();
//		if(ch>=48 && ch<=57){
//			digit+=1;
//		}
//		else if(ch>=65 && ch<=90 || ch>=97 && ch<=122){
//			letter +=1;
//		}
//		else if(ch==13 || ch==32){
//			blank+=1;
//		}
//		else{
//			other+=1;
//		}
//	}
//		printf("letter=%d\nblank=%d\ndigit=%d\nother=%d\n",letter,blank,digit,other);
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	int a[35];
//	int i,minn=9999,maxn=0,sum=0;
//	for(i=0;i<30;i++){
//		scanf("%d",&a[i]);
//	}
//	for(i=0;i<30;i++){
//		if(a[i]<minn){
//			minn=a[i];
//		}
//		if(a[i]>maxn){
//			maxn=a[i];
//		}
//		sum+=a[i];
//	}
//	printf("maxn=%d\nminn=%d\naverage=%lf",maxn,minn,sum/30.0);
//	
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	int i,j;
//	for(i=1;i<=9;i++){
//		for(j=0;j<=9;j++){
//			printf("%d%d ",i,j);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	long long sum=0;
//	for(i=1;i<1000;i++){
//		if(i%2 !=0){
//			sum+=i;
//		}
//	}
//	printf("%lld",sum);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int i,n;
//	double sum=0;
//	scanf("%d",&n);
//	for(i=1;i<=n;i++){
//		sum+=1.0/i;
//	}
//	printf("sum=%lf",sum);
//	return 0;
//}

//#include<stdio.h>
//int main(){
//	int i,n,num=1;
//	scanf("%d",&n);
//	double sum=0,a=1.0,num1;
//	for(i=1;i<=n;i++){
//		num1=a*1.0/num*1.0;
//		sum+=num1;
//		num+=3;
//		a=-a;
//	}
//	printf("sum=%.3lf",sum);
//	return 0;
//}


//#include<stdio.h>
//int main(){
//	int i,n,num,minn=99999;
//	scanf("%d",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&num);
//		if(num<minn){
//			minn=num;
//		}
//	}
//	printf("%d",minn);
//	return 0;
//}



int main(void)

{       int n[3],i,j,k;

for(i=0;i<3;i++) n[i]=0;

k=2;

for(i=0;i<k;i++)

for(j=0;j<k; j++) n[j]=n[i]+1;

printf("%d\n",n[1]);

return 0;  }








