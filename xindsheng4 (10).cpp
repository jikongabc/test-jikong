#include<stdio.h>
#include<string.h>
int main(){
    char a[10], b[10];
    gets(a);
    gets(b);
    int x = 1, y = 1;
    for(int i = 0; i < strlen(a); i++) x *= (a[i] - 'A' + 1);
    for(int i = 0; i < strlen(b); i++) y *= (b[i] - 'A' + 1);
    if(x % 47 == y % 47) printf("GO");
    else printf("STAY");
    return 0;
}