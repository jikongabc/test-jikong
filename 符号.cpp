#include<stdio.h>
int main(){
	int a, b, c;
	char op;
	scanf("%c%d%d%d",&op, &a, &b, &c);
	long long res;
	if(op =='+') res = a + b;
	else if(op == '-') res = a - b;
	else if(op == '*') res = a * b;
	else res = a / b;
	if(res == (long long)c){
		printf("Yes\n");
		printf("%d%c%d=%d",a, op, b, c);
	}
	else printf("No");
	return 0;
} 
