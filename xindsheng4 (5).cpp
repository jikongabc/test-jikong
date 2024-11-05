#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		char s[1010];
		gets(s);
		puts(s);
	}
	return 0;
}