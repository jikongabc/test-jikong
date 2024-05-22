#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 510, M = N * N / 2;
int n, k, m;
int fa[N];
int x[M], y[M];
int cnt;

struct Edge{
    int a, b;
    double w;
} edges[M];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

double kruskal(){
    sort(edges, edges + cnt, cmp);
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    double res = 0;
    for (int i = 0; i < cnt;i++){
        if(m<=k)
            break;
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res = max(res, w);
            m--;
        }
    }
    return res;
}

double get_dist(int x1,int y11,int x2,int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2));
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n - 1;i++){
        for (int j = i + 1; j < n;j++){
            edges[cnt++] = {i, j, get_dist(x[i], y[i], x[j], y[j])};
        }
    }
    m = n;
    printf("%.2lf", kruskal());
    return 0;
}