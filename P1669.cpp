// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <string>
// #include <map>
// #include <set>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 1005;
// int g[N][N];
// int dist[N];
// bool st[N];
// int n, m;
// int prim(){
//     int res = 0;
//     memset(dist, 0, sizeof dist);
//     for (int i = 0; i < n;i++){
//         int t = -1;
//         for (int j = 1; j <= n;j++){
//             if(!st[j] && (t==-1|| dist[t]<dist[j]))
//                 t = j;
//         }
//         if(i&& dist[t]==0)
//             return 0;
//         if(i)
//             res += dist[t];
//         st[t] = 1;
//         for (int j = 1; j <= n;j++){
//             dist[j] = max(dist[j], g[t][j]);
//         }
        
//     }
//     return res;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     memset(g, 0, sizeof g);
//     while(m--){
//         int a, b, w;
//         cin >> a >> b >> w;
//         g[a][b] = g[b][a] = max(g[a][b], w);
//     }
//     int t = prim();
//     if(t==0)
//         cout << -1;
//     else
//         cout << t;
//     return 0;
// }

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
const int N = 1005, M = 20005;
int n, m;
int fa[M];

struct Edge{
    int a, b, w;
} edges[M];

bool cmp(Edge a,Edge b){
    return a.w > b.w;
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
    }
    if(cnt<n-1)
        return - 1;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    cout << kruskal();
    return 0;
}