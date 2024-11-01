#include <stdio.h>
#include <math.h>
#include <string.h>
int n, m;
int a[1000005], b[1000005];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);
	long long res = 0;
	for(int i = 0; i < n; i++) res += b[a[i]];
	printf("%lld", res);
	return 0;
}