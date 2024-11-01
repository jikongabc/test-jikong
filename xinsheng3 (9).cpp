#include <stdio.h>
#include <math.h>
#include <string.h>
int n;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int cnt[105] = {0};
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
		for(int i = 1; i <= 30; i++){
			printf("%d ", cnt[i]);
		}
		printf("\n");
	}	
	return 0;
}
