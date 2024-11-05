#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char s[200005];
	int i = 0;
	int pos = -1;
	scanf("%d", &n);
	getchar();
	gets(s); 
	if(strlen(s) == 1){
		puts(s);
		return 0;
	} 
	while(i < strlen(s)){
		if(s[i] > s[i + 1]) break;
		i++;
	}
	if(i < strlen(s)) pos = i;
	else{
		puts(s);
		return 0;
	}
	for(int i = 0; i < strlen(s); i++){
		if(i != pos) printf("%c", s[i]);
	}
	return 0;
}