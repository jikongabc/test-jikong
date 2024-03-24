//p5742
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
const int N = 1005;
struct node{
    int id, a, b, sum, judge;
} p[N];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d%d%d", &p[i].id, &p[i].a, &p[i].b);
        p[i].judge= p[i].a * 7 + p[i].b * 3;
        p[i].sum= p[i].a  + p[i].b ;
        if(p[i].sum>140 && p[i].judge>=800)
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }
    return 0;
}