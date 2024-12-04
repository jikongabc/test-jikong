#include <stdio.h>
int main(){
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	int sum = 0;
	for(int i = l; i <= r; i++){
		int cnt = 0;
		int st[100] = {0};
		int num = i;
		while(num){
			int t = num % 10;
			if(st[t] == 0){
				st[t] = 1;
				cnt++;
			}
			num /= 10;
		}
		if(cnt <= k) sum += i;
	}
	printf("%d", sum);
	return 0;
}