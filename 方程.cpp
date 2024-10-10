#include <stdio.h>
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a == 0) printf("1");
	else{
	int deta = b * b - 4 * a * c;
	if(deta > 0) printf("2");
	else if(deta == 0) printf("1");
	else printf("0");
	}
	return 0;
}