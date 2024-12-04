#include <stdio.h>
int main(){
	int n, m;
	char a[100];
	scanf("%d%d", &n, &m);
	getchar();
	gets(a);
	while(m--){
		char c, d;
		scanf("%c", &c);
		getchar();
		scanf("%c", &d);
		for(int i = 0; i < n; i++){
			if(a[i] == c) a[i] = d;
		}
		getchar();
	}
	puts(a);
	return 0;
}