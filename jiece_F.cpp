#include<stdio.h>
int a[1000005];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	int min_price = a[0];
	int res = a[1] - a[0];
	for(int i = 1; i < n; i ++){
		int t = a[i] - min_price;
		if(t > res) res = t;
		if(a[i] < min_price) min_price = a[i];
	}
	printf("%d", res);
	return 0;
}