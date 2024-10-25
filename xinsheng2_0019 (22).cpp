#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int sum = 0;
	int t = 2;
	while(sum + t <= n){
		bool flag = false;
		for(int i = 2; i * i <= t; i++){
			if(t % i == 0){
				flag = true;
				break;
			}
		}
		if(!flag){
			cnt++;
			printf("%d\n", t);
			sum += t;
		}
		t++;
	}
	printf("%d", cnt);
	return 0;
}
