#include<stdio.h>

int is_prime(int x){
	if(x == 1 || x == 0) return 0;
	for(int i = 2; i * i <= x; i ++){
		if(x % i == 0) return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	int t = n;
	while(t){
		sum += t % 10;
		t /= 10;
	}
	if(is_prime(n) == 1 && is_prime(sum) == 1) puts("YES");
	else puts("No");
	return 0;
}