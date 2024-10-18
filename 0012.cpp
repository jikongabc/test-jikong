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
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = n; i <= m; i++){
		if(pd(i)) res++;
	}
	printf("%d", res);
	return 0;
}