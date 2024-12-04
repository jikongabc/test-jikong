#include <stdio.h>
#include <math.h>
#include <string.h>
// const int N =  ;

int main(){
	int n, m, a;
	scanf("%d%d%d", &n, &m, &a);
	long long res = (long long)(n / a) * (m / a); 
	printf("%lld", res);
	return 0;
}