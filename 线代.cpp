#include<stdio.h>

int main(){
    int a[4][4];
    int res = 1; 
    long long maxn = -1e18;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= 3; i ++){
        long long sum = 0;
        for(int j = 1; j <= 3; j++){
            int a11, a12, a21, a22;
            int cnt = 0;
            for(int i1 = 1; i1 <=3; i1++){
                for(int j1 = 1; j1 <= 3; j1++){
                    if(i1 != i && j1 != j){
                        cnt ++;
                        if(cnt == 1) a11 = a[i1][j1];
                        else if(cnt == 2) a12 = a[i1][j1];
                        else if(cnt == 3) a21 = a[i1][j1];
                        else if(cnt == 4) a22 = a[i1][j1];
                    }
                }
            }
            long long t = a11 * a22 - a12 * a21;
            sum += t;
        }
        if(sum > maxn){
            maxn = sum;
            res = i;
        }
    }
    long long sum1 = 1;
    for(int j = 1; j <= 3; j++){
        int a11, a12, a21, a22;
        int cnt = 0;
        for(int i1 = 1; i1 <= 3; i1++){
            for(int j1 = 1; j1 <= 3; j1++){
                if(i1 != res && j1 != j){
                    cnt ++;
                    if(cnt == 1) a11 = a[i1][j1];
                    else if(cnt == 2) a12 = a[i1][j1];
                    else if(cnt == 3) a21 = a[i1][j1];
                    else if(cnt == 4) a22 = a[i1][j1];
                }
            }
        }   
        long long t = a11 * a22 - a12 * a21;
        sum1 *= t;
    }
    if(sum1 % 2 == 1){
        printf("%lld",sum1);
    }
    else printf("-1");
     
    return 0;
}

