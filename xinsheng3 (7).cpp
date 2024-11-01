#include <stdio.h>
#include <math.h>
#include <string.h>
int a[1010];

int main(){
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		int flag = 1;
		for(int j = 2; j * j <= a[i]; j++){
			if(a[i] % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			a[i] = -1;
			cnt++;
		}
	}
	for(int i = n - 1; i >= 0; i--){
		printf("%d ", a[i]);
	}
	printf("\n%d", cnt);
	return 0;
}