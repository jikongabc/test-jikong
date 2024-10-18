#include<stdio.h>
#include<math.h>
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, x;
		int minn = 999999999;
		int res;
		scanf("%d%d", &n, &x);
		for(int i = 1; i <= n; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			int s = abs(a - x);
			int t;
			if(s % b == 0) t = s / b;
			else t = s / b + 1;
			if(t < minn){
				minn = t;
				res = i;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
