#include<stdio.h>
int a[1010];

int main(){
	int n, k;
	int res = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n - k + 1; i++){
		int cnt[1010] = {0};
		for(int j = i; j <= i + k - 1;  j++){
			cnt[a[j]]++;
		}
		int t = 0;
		while(cnt[t]) t++;
		if(t > res) res = t;
	}
	printf("%d", res);
	return 0;
}