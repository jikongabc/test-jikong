#include<stdio.h>
int a[105][105];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int t;
    scanf("%d", &t);
    while(t--){
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}