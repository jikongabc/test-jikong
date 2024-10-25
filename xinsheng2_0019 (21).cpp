#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	bool flag = false;
	if(n == 1){
		printf("NO.");
		return 0;
	}
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			printf("NO.");
			flag = true;
			break;
		}
	}
	if(!flag)
		printf("YES.");
	return 0;
}