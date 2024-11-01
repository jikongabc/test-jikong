#include <stdio.h>
int C[20][20];

int main(){
    for(int i = 0; i < 20; i++){
        for(int j = 0;j <= i; j++){
            if(j == 0 ) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", C[x][y]);
    return 0;
}
