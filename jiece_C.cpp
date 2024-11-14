#include<stdio.h>
#include<string.h>
int time[25], flag[25];
int main(){
	int n, m;
	scanf("%d%d", &n , &m);
	while(m --){
		int a, b;
        char c[50] = {0};
		scanf("%d%d", &a, &b);
		getchar();
		gets(c);
		if(flag[a] == 0){
			if(c[0] == 'A'){
				flag[a] = 1;
				time[a] += b;
			}
			else time[a] += 20;
		}
	}
	int res = 0, cnt = 0;
	for(int i = 1; i <= n; i ++){
		if(flag[i] == 1){
			res += time[i];
			cnt ++;
		}
	}
	printf("%d %dmin", cnt, res);
	return 0;
}