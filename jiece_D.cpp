#include<stdio.h>
int cnt_A[1010], cnt_B[1010];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n ; i ++){
		int x;
		scanf("%d", &x);
		cnt_A[x] ++;
	}
	for(int i = 0; i < m; i ++){
		int x;
		scanf("%d", &x);
		cnt_B[x] ++;
	}
	for(int i = 1; i <= 1000; i ++){
		if(cnt_A[i] == 1 && cnt_B[i] == 1) printf("%d ", i);
	}
	printf("\n");
	for(int i = 1; i <= 1000; i ++){
		if(cnt_A[i] == 1 || cnt_B[i] == 1) printf("%d ", i);
	}
	printf("\n");
	for(int i = 1; i <= 1000; i ++){
		if(cnt_A[i] == 0 && cnt_B[i] == 1){
			printf("-1");
			return 0;
		}
	}
	for(int i = 1; i <= 1000; i ++){
		if(cnt_A[i] == 1 && cnt_B[i] == 0) printf("%d ", i);
	}
	return 0;
}