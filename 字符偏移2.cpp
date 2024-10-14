#include<stdio.h>
int main(){
	char c;
	int k;
	scanf("%c%d", &c, &k);
	k %= 26;
	char res;
	res = c + k > 'z' ? c + k - 26 : c + k; 
	printf("%c", res);
	return 0;
} 
