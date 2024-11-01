#include <stdio.h>
#include <math.h>
#include <string.h>
const int mod = 1e5 + 3;
int n;
long long a[1000005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		if(i == 1 || i == 2) a[i] = 1;
		else a[i] = (a[i - 1] + a[i - 2]) % mod;
	}
	printf("%lld", a[n]);

	return 0;
}