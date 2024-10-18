#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= 999999; i++){
		int sum = 0;
		int t = i;
		while(t){
			sum += t % 10;
			t /= 10;
		}
		if(sum % n == 0) res++;
	}
	printf("%d", res);
	return 0;
} 
