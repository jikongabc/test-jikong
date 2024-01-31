//#include<stdio.h>
//int main() {
//	int i;
//	for (i = 1; i <= 100; i++) {
//		if (i % 3 == 0) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int a, b, c;
//	int num;
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (b > a) {
//		num = a;
//		a = b;
//		b=num;
//	}
//	if (c > a) {
//		num = a;
//		a = c;
//		c = num;
//	}
//	if (c > b) {
//		num = c;
//		c = b;
//		b = num;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int a, b, c;
//	while (scanf_s("%d%d%d", &a, &b, &c) !=EOF) {
//		if (a + b > c && a + c > b && b + c > a) {
//			if (a == b && b == c) {
//				printf("Equilateral triangle!\n");
//			}
//			else {
//				if (a == b || b == c || a == c) {
//					printf("Isosceles triangle!\n");
//				}
//				else {
//					printf("Ordinary triangle!\n");
//				}
//			}
//		}
//		else {
//			printf("Not a triangle!\n");
//		}
//	}
//	
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int i;
//	double sum=0,num=1.0;
//	for (i = 1; i <= 100; i++) {
//		sum += 1.0 * num / i * 1.0;
//		num = -num;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int i,n,num,sum=0;
//	for (i = 1; i <= 100; i++) {
//		num = i;
//		while (num != 0) {
//			n = num % 10;
//			num = num / 10;
//			if (n == 9) {
//				sum += 1;
//			}
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int i;
//	for (i = 1000; i <= 2000; i++) {
//		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

#include<stdio.h>
int main() {
	int i, n,num=-9999999;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &n);
		if (n > num) {
			num = n;
		}
	}
	printf("%d", num);
	return 0;
}