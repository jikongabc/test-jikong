#include<stdio.h>
#include<string.h>
int main(){
	char a[1010], b[1010];
	gets(a);
	gets(b);
	for(int i = 0; i < strlen(a); i++) if(a[i] <= 'Z' &&a[i] >= 'A') a[i] += 32;
	for(int i = 0; i < strlen(b); i++) if(b[i] <= 'Z' &&b[i] >= 'A') b[i] += 32;
	int t = strcmp(a, b);
	if(t > 0) printf(">");
	else if(t == 0) printf("=");
	else printf("<");
	return 0;
}