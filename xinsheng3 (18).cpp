#include <stdio.h>
#include <math.h>
#include <string.h>
int n;
int a[105];
int l, r;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d%d", &l, &r);
	printf("%d", a[r] - a[l - 1]);
	return 0;
}