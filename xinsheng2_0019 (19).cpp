#include<stdio.h>
int main(){
	int n;
	int maxn = 0;
	while(~scanf("%d", &n)){
		if(n >= maxn) maxn = n;
	}
	printf("%d", maxn);
	return 0;
}