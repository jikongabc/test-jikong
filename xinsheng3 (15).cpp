#include <stdio.h>
int a[1000005], b[1000005];  
int n;

int is_happyNumber(int x){  //判断快乐数
	while(x >= 10){
		int sum = 0;
		while(x){
			int t = x % 10;
			sum += t * t;
			x /= 10;
		}
		x = sum;
	}
	if(x == 1){
		return 1; //如果x是快乐数就返回1
	}
	else{
		return 0; //不是就返回0
	}
}

int main(){
	scanf("%d", &n);
	int sum = 0; 
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		b[i] = a[n - 1 - i];
		if(b[i] != a[i]) cnt++;
	}
	if(cnt / 2 == 1) printf("Happyhappyhappy\n");
	else{
		printf("Sadsadsad\n");
		if(is_happyNumber(sum) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}