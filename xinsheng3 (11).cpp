#include <stdio.h>
#include <math.h>
#include <string.h>
int n;
int a[25][25];
int main(){
	a[1][1] = 1;
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(i == 1) a[i][j] = 1;
			else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
