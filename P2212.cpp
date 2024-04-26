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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULl = unsigned long long;
typedef pair<int, int> PII;
const int N = 1005, M = 2e6 + 10;
int n, m;
int k;
int fa[N];
int x[N], y[N];
struct Edge{
    int a, b, w;
} edges[M];

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int find(int x){
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    int res = 0, cnt = 0;
    sort(edges, edges + k, cmp);
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 0; i < k; i++){
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            fa[a] = b;
            res += w;
            cnt++;
        }
    }
    if(cnt<n-1)
        return -1;
    else
        return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            int w = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if(w>=m)
                edges[k++] = {i, j, w};
        }
    }
    cout << kruskal();
    return 0;
}