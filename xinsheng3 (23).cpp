#include<stdio.h>
int a[100005];
int b[100005];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
	}
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		int t = b[r] - b[l - 1];
		if(t % 2 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}