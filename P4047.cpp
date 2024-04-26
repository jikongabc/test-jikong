#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
using LL = long long;
using ULl = unsigned long long;
const int N = 1e3 + 10, M = 2e3 + 10;
int n, k;
int fa[N];
int cnt;

struct node{
    int x, y, id;
} p[N];

struct Edge{
    int a, b;
    double w;
} edges[M];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}
bool cmpx(node a,node b){
    return a.x < b.x;
}
bool cmpy(node a,node b){
    return a.y < b.y;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

double kruskal(){
    double res = 0.0;
    sort(edges, edges + cnt, cmp);
    for (int i = 1; i <= n;i++)
        fa[i] = i;
        for (int i = 0; i < cnt; i++)
        {
            int a = edges[i].a, b = edges[i].b;
            double w = edges[i].w;
            a = find(a), b = find(b);
            if (a != b)
            {
                fa[a] = b;
                // res += w;
                res = max(res, w);
                n--;
                if(n==k-1)
                    return res;
            }
        }
    // return res;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        p[i] = {x, y, i};
    }
    for (int i = 1; i < n;i++){
        for (int j = i+1; j <= n;j++){
            double w = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
            edges[cnt++] = {i, j, w};
        }
    }
        // sort(p + 1, p + 1 + n, cmpx);
        // for (int i = 1; i < n;i++){
            // double w = sqrt((p[i].x - p[i + 1].x) * (p[i].x - p[i + 1].x) + (p[i].y - p[i + 1].y) * (p[i].y - p[i + 1].y));
            // edges[cnt++] = {p[i].id, p[i + 1].id, w};
        // }
        // sort(p + 1, p + 1 + n, cmpy);
        // for (int i = 1; i < n;i++){
        //     double w = sqrt((p[i].x - p[i + 1].x) * (p[i].x - p[i + 1].x) + (p[i].y - p[i + 1].y) * (p[i].y - p[i + 1].y));
        //     edges[cnt++] = {p[i].id, p[i + 1].id, w};
        // }
        printf("%.2lf", kruskal());
    return 0;
}
