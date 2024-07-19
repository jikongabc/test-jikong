#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 4*505*505, M = 505;
int n;
int d[M][M];
int fa[N];
int cnt;
int sz[N];

int get(int x,int y){
    return (x - 1) * n + y;
}

struct Edge{
    int a, b, w;
} edges[N];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    sort(edges, edges + cnt, cmp);
    for (int i = 1; i <= n * n;i++){
        fa[i] = i;
        sz[i] = 1;
    }
    int res = 0;
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            sz[b] += sz[a];
            if (sz[b] >= (n * n + 1) / 2){
                return w;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n; j++){
            cin >> d[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j < n;j++){
            int a = get(i, j), b = get(i, j + 1), w = abs(d[i][j] - d[i][j + 1]);
            edges[cnt++] = {a, b, w};
            edges[cnt++] = {b, a, w};
        }
    }
    for (int j = 1; j <= n;j++){
        for (int i = 1; i < n;i++){
            int a = get(i, j), b = get(i + 1, j), w = abs(d[i][j] - d[i + 1][j]);
            edges[cnt++] = {a, b, w};
            edges[cnt++] = {b, a, w};
        }
    }
    cout << kruskal();
    return 0;
}