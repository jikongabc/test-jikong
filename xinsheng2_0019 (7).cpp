//#include <stdio.h>
//int main(){
//	int n;
//	scanf("%d", &n);
//	int res = 0x3f3f3f3f;
//	for(int i = 0; i < n; i++){
//		int x;
//		scanf("%d", &x);
//		if(x < res) res = x;
//	}
//	printf("%d", res);
//	return 0;
//}
#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[10005];
	int res = 0x3f3f3f3f;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(res > a[i]) res = a[i];
	}
	printf("%d", res);
	return 0;
} 
