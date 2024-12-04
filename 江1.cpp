#include <stdio.h>

int main(){
	long long a, b, c;
	long long res = 1e18;
	scanf("%lld%lld%lld", &a, &b, &c);
	if(a < res) res = a;
	if(b < res) res = b;
	if(c < res) res = c;
	printf("%lld", res);
	return 0;
}