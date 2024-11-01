#include<stdio.h>
int cnt[10];

int main(){
	long long m, n;
	scanf("%lld%lld", &m , &n);
	for(long long i = m; i <= n; i++){
		long long t = i;
		if(i == 0) cnt[0]++;
		while(t){
			cnt[t % 10]++;
			t /= 10;
		}
	}
	for(int i = 0; i < 10; i++){
		printf("%d ", cnt[i]);
	}
	return 0;
}