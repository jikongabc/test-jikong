#include<stdio.h>
int a[20005];
int main(){
	int T;
	scanf("%d", &T);
	while(T --){
		int n, x;
		int cnt[20005] = {0}, cnt1[20005] = {0};
		scanf("%d%d", &n, &x);
		for(int i = 0; i < n; i ++){
			scanf("%d", &a[i]);
			if(a[i] > 20000) continue;
			cnt[a[i]] ++;
		}
		int t = 0;
		while(t <= 20000){
			if(cnt[t] > 1){
				int tt = t % x;
				cnt1[tt] += cnt[t] - 1;
				cnt[t] = 1;
			}
			else if(cnt[t] == 0){
				int tt = t % x;
				if(cnt1[tt] > 0){
					cnt1[tt] --;
					cnt[t] = 1;
				}
				else{
					printf("%d\n", t);
					break;
				}
			}
			t ++;
		}
	}
	return 0;
}