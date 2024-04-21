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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1005, M = 10005;
int n,m,k;
int fa[N];

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

int kruskal(){
    sort(edges, edges + m, cmp);
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    int res = 0, cnt = 0;
    for (int i = 0; i < m;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res += w;
            cnt++;
        }
        if(cnt==n-k)
            return res;
    }
    if(cnt<n-k)
        return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    int t = kruskal();
    if(t==-1)
        cout << "No Answer";
    else
        cout << t;
    return 0;
}

