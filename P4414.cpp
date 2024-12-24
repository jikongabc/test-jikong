#include<iostream>
using namespace std;
int main(){
	int a[4];
for (int i = 0; i < 3; i++) {
    scanf("%d", &a[i]);
}

getchar();
getchar();
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 - i; j++) {
        if (a[j] > a[j + 1]) {
            int t = a[j + 1];
            a[j + 1] = a[j];
            a[j] = t;
        }
    }
}

char b[4];
/*
for (int i = 0; i < 3; i++) {
    scanf("%c", &b[i]);
    if (i != 2) {
        printf("%d ", a[b[i] - 65]);
    }
}
printf("%d", a[b[2] - 65]);
return 0;
*/

for (int i = 0; i < 3; i++) {
    scanf("%c", &b[i]);
    if (b[i] == 'A') {
        printf("%d ", a[0]);
    }
    if (b[i] == 'B') {
        printf("%d ", a[1]);
    }
    if (b[i] == 'C') {
        printf("%d ", a[2]);
    }
}

return 0;

	return 0;
}