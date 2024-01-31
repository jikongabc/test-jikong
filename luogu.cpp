//#include<stdio.h>
//int main() {
//	int num1, num2, i, sum = 0;
//	int a[10] = { 0 };
//	for (i = 0; i < 5; i++) {
//		scanf_s("%d", &a[i]);
//	}
//	for (i = 0; i < 5; i++) {
//		if (i == 0) {
//			num1 = a[i] / 3;
//			num2 = a[i] % 3;
//			a[i] = num1;
//			a[4] += num1;
//			a[1] += num1;
//			sum += num2;
//		}
//		else if(i !=4) {
//			num1 = a[i] / 3;
//			num2 = a[i] % 3;
//			a[i] = num1;
//			a[i-1] += num1;
//			a[i+1] += num1;
//			sum += num2;
//		}
//		else {
//			num1 = a[i] / 3;
//			num2 = a[i] % 3;
//			a[i] = num1;
//			a[3] += num1;
//			a[0] += num1;
//			sum += num2;
//		}
//	}
//	for (i = 0; i < 5; i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n%d", sum);
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	int a, b, c;
//	scanf_s("%d%d%d", &a, &b, &c);
//	printf("%8d %8d %.8d", a, b, c);
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int n, k, i;
//	long long num;
//	long long sum = 0;
//	long long a[1000005] = { 0 };
//	scanf_s("%d%d", &n, &k);
//	for (i = 1; i <= n; i++) {
//		scanf_s("%lld", &num);
//		if (i != k) {
//			a[i] += num;
//		}
//		else {
//			a[i] -= num;
//		}
//		sum += a[i];
//
//	}
//	printf("%lld", sum);
//	return 0;
//}


//#include<stdio.h>
//int main() {
//	double x, y;
//	scanf_s("%d%d", &x, &y);
//	if (x <= 1 && x >= -1 && y <= 1 && y >= -1) {
//		printf("yes");
//	}
//	else {
//		printf("no");
//	}
//	return 0;
//}

