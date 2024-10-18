#include<stdio.h>
int main(){
	for(int i = 100; i <= 999; i++){
		int t = i;
		int sum = 0;
		while(t){
			int tt = t % 10;
			sum += tt * tt * tt;
			t /= 10;
		}
		if(sum == i) printf("%d\n", i);
	}
	return 0;
}