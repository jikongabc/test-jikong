#include<stdio.h>
#include<string.h>
int main(){
	char s[1010], s1[15];
	gets(s);
	gets(s1);
	int cnt = 0;
	int n = strlen(s), m = strlen(s1);
	for(int i = 0; i < n; i++){
		int flag = 1;
		for(int j = 0; j < m; j++){
			if(s[(i + j) % n] != s1[j]){
				flag = 0;
				break;
			}
		}
		if(flag = 0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}