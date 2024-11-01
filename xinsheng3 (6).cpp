#include<stdio.h>
int a[1010][1010];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = n; i > 0; i--){
		for(int j = m; j > 0; j--){
			if(a[i][j] == 1) printf("%d %d\n", i, j);
		}
	}
	return 0;
}