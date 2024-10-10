#include<stdio.h>
int main(){
	int x;
	scanf("%d", &x);
	if(x ==1){
		int a, b;
		char c;
		int res;
		scanf("%d%c%d", &a, &c, &b);	
		if(c == '+'){
			res = a + b;
		}
		else res = a - b;
		printf("%d", res);
	}
	else if(x == 2){
		int a, b;
		char c;
		double res;
		scanf("%d%c%d", &a, &c, &b);
		if(c == '*'){
			res = a * b;
		}
		else if(c == '/'){
			res = a * 1.0 / b * 1.0;
		}
		printf("%.2lf", res);
	}
	else{
		int n;
		scanf("%d", &n);
		if(n % 4 == 0 && n % 100 != 0 || n % 400 == 0){
			printf("YES");
		}
		else printf("NO");
	}
	return 0;
}
