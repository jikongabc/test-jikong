#include<stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			if(i % 3 == 1) printf("a");
			else if(i % 3 == 2) printf("b");
			else printf("c");
		}
		printf("\n");
	}
	return 0;
}