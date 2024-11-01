#include<stdio.h>
int main(){
	long long n;
	scanf("%lld", &n);
	long long t = 0;
	while(n){
		t = t * 10 + n % 10;
		n /= 10;
	}
	printf("%lld", t);
	return 0;
}