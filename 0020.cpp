#include<stdio.h>

int rev(int a){
	int res = 0;
	while(a){
		int t = a % 10;
		res = res * 10 + t;
		a /= 10;
	}
	return res;
}

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b), a || b){
		if(rev(a) + rev(b) == rev(a + b)){
			printf("%d\n", a + b);
		}
		else printf("NO\n");
	}
	return 0;
}