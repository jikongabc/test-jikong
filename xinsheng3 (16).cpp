#include <stdio.h>
#include <math.h>
#include <string.h>
int n;
int a[105], b[105];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= n; i++){
		b[i] = b[i - 1] + a[i];
		printf("%d ", b[i]);
	}

	return 0;
}