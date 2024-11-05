#include<stdio.h>
#include<string.h>
int main(){
	char s[105];
	int i = 0;
	gets(s); 
	while((s[i] < '0' || s[i] > '9') && i < strlen(s)) i++;
	long long t = -1;
	int cnt = 0;
	while(s[i] >= '0' && s[i] <= '9' && i < strlen(s)){
		if(cnt == 0) t = s[i] - '0';
		else t = t * 10 + s[i] - '0';
		i++;
		if(t > 1e9) break;
		cnt++;
	}
	if(t > 1e9 || cnt == 0) printf("-1");
	else printf("%d", t); 
	return 0;
}
