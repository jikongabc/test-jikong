#include <stdio.h>
#include <math.h>
#include <string.h>
int n;
int a[200005], b[200005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	for(int i = 0; i < n; i++){
		printf("%d %d\n", a[i], b[n - 1 - i]);
	}
	return 0;
}