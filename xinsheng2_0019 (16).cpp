#include<stdio.h>

bool pd(int x){
	if(x == 0) return true;
	while(x){
		int t = x % 10;
		if(t == 0 || t == 6 || t == 8 || t == 9) return true;
		x /= 10;
	}
	return false;
}

int main(){
	int res = 0;
	int n;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++){
		if(pd(i)) res++;
	}
	printf("%d", res);
	return 0;
}