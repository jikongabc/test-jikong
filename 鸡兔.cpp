#include<stdio.h>
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	a *= 2;
	if(a >= b){
		printf("YES");
	}
	else{
		int res = (b - a + 1)/ 2;
		printf("NO %d",res);
	}
	return 0;
}
