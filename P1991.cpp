#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505, M = 125000;
int n, m;
int cnt;
int fa[N];
double x[N], y[N];
struct Edge
{
    int a, b;
    double w;
} edges[M];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

double kruskal(){
    double res = 0;
    sort(edges, edges + cnt, cmp);
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    int count = 0;
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res = max(res, w);
            count++;
        }
        if(count==n-m)
            return res;
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n-1;i++){
        for (int j = i+1; j < n;j++){
            if(i==j)
                continue;
            double w = sqrt((x[i] - x[j]) * (x[i] - x[j])*1.0 + (y[i] - y[j]) * (y[i] - y[j])*1.0);
            edges[cnt].a = i, edges[cnt].b = j, edges[cnt].w = w;
            cnt++;
        }
    }
    // for (int i = 0; i < cnt;i++){
    //     cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w<<endl;
    // }
        double t = kruskal();
    printf("%.2lf", t);
    return 0;
}