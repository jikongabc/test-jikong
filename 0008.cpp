#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int cnt = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j ++){
			printf("%02d", cnt);
			cnt++;
		}
		printf("\n");
	}
	return 0; 
}