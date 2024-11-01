#include<stdio.h>
int a[1000005];
int main(){
	int n;
	int res = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int cnt = 1;
	for(int i = 0; i < n - 1; i++){
		if(a[i] < a[i + 1]) cnt++;
		else{
			if(cnt > res) res = cnt;
          	cnt =  1;
		}
	}
	printf("%d", res);
	return 0;
}