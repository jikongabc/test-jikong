#include<stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j != m) printf("%d ", cnt);
				else printf("ACM");
				cnt++;
			}
			printf("\n");
		}
	}

	return 0;
}