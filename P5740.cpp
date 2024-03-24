#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
using namespace std;
const int N = 1005;
struct node{
    char name[8];
    int Chinese, math, English, sum, id;
} p[N];

bool cmp(const node&a,const node&b){
    if(a.sum==b.sum)
        return a.id < b.id;
    return a.sum > b.sum;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%s", p[i].name);
        scanf("%d", &p[i].Chinese);
        scanf("%d", &p[i].math);
        scanf("%d", &p[i].English);
        p[i].sum = p[i].Chinese + p[i].English + p[i].math;
        p[i].id = i;
    }
    sort(p, p + n, cmp);
    printf("%s %d %d %d", p[0].name, p[0].Chinese, p[0].math, p[0].English);
    return 0;
}