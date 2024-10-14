#include<stdio.h>
//a b c
//d e f
//g h i
int main(){
	int a, b, c, d, e, f, g, h, i;
	int A, B, C, D, E, F, G, H, I;
	scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
	A = e * i - f * h;
	B = d * i - f * g;
	C = d * h - e * g;
	D = b * i - c * h;
	E = a * i - c * g;
	F = a * h - b * g;
	G = b * f - c * e;
	H = a * f - c * d;
	I = a * e - b * d;
	int res1 = A + B + C;
	int res2 = D + E + F;
	int res3 = G + H + I;
	int ans1 = A * B * C;
	int ans2 = D * E * F;
	int ans3 = G * H * I; 
	int maxn = 0;
	int pos;
	if(res1 > maxn) pos = 1;
	if(res2 > maxn) pos = 2;
	if(res3 > maxn) pos = 3;
	int result;
	if(pos == 1) result = ans1;
	else if(pos == 2) result = ans2;
	else result = ans3;
	if(result % 2 == 1) printf("%d", result);
	else printf("-1"); 
	return 0;
} 
