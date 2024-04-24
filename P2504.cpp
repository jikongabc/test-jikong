#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1005, M = 5e5 + 10;
int n, m;
double x[N], y[N];
int fa[N];
double g[N];
int cnt;

struct Edges{
    int a, b;
    double w;
} edges[M];

bool cmp(Edges a,Edges b){
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
    double res = 0.0;
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res = max(res, w);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 1; i <= m;i++){
        cin >> g[i];
    }
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            double w = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            edges[cnt++] = {i, j, w};
        }
    }
    double t=kruskal();
    int ans = 0;
    for (int i = 1; i <= m;i++){
        if(g[i]>=t)
            ans++;
    }
    cout << ans;
    return 0;
}