#include <stdio.h>
#include <math.h>
#include <string.h>
const int mod = 998244353;

long long g(int n){
	if(n == 1) return 1;
	return (g(n - 1) * n) % mod;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	long long res = (g(a) * g(b)) % mod;
	printf("%lld", res);
	return 0;
}
