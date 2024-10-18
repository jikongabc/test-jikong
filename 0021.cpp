#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	while(n >= 10){
		bool flag = false;
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0){
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
		int sum = 0;
		int t = n;
		while(n){
			int t = n % 10;
			sum += t * t;
			n /= 10;
		}
		n = sum;
	}
	if(n == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	printf("%d", cnt);
	return 0;
}

