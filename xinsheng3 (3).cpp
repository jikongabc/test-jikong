#include<stdio.h>
int a[105][105];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int flag = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n; j++){
			if(a[i][j] > a[i][j + 1]){
				flag = 0;
				printf("%d ", i);
				break;
			}
		}
	}
	printf("\n");
	for(int j = 1; j <= n; j++){
		for(int i = 1; i < n; i++){
			if(a[i][j] > a[i + 1][j]){
				flag = 0;
				printf("%d ", j);
				break;
			}
		}
	}
	printf("\n");
	if(flag == 1) printf("OK");
	return 0;
}