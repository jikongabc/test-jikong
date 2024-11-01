#include<stdio.h>
int main(){
    double m[12][12];
    int a, b, cnt = 0;
    char op;
    scanf("%d%d", &a, &b);
    getchar();
    scanf("%c", &op);
    double sum = 0;
    for(int i = 0;i < 12; i++){
        for(int j = 0;j < 12; j++){
            scanf("%lf", &m[i][j]);
        }
    }
    while(a < 12 && b < 12){
        sum = sum + m[a][b];
        a++;
        b++;
        cnt++;
    }
    double res = sum * 1.0 / cnt;
    if(op == 'S'){
        printf("%.1lf", sum);
    }else{
        printf("%.1lf", res);
    }
    return 0;
}