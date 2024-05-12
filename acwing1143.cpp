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
const int N = 2005, M = 10005;
int n, m, k;
int fa[N];
int res;
struct Edge{
    int a, b, w;
} edges[M];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void kruskal(){
    sort(edges, edges + k,cmp);
    for (int i = 0; i < k;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res += w;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
        for (int i = 0; i < m; i++)
        {
            int p;
            int a, b, w;
            cin >> p >> a >> b >> w;
            if(p==1){
                res+=w;
                a = find(a), b = find(b);
                fa[a] = b;
            }
            else
                edges[k++] = {a, b, w};
        }
        kruskal();
        cout << res;
        return 0;
}