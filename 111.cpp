// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<vector>
// #include<queue>
// #include<deque>
// #include<map>
// #include<set>
// #include<unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 2e5 + 10;
// int n;
// int h[N], e[N], ne[N], idx;
// bool st[N];
// int ans = N;

// void add(int a,int b){
//     e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }

// int dfs(int u){
//     st[u] = 1;
//     int res = 0, sum = 1;
//     for (int i = h[u]; i != -1;i=ne[i]){
//         int j = e[i];
//         if(st[j])
//             continue;
//         int s = dfs(j);
//         res = max(res, s);
//         sum += s;
//     }
//     res = max(res, n - sum);
//     ans = min(ans, res);
//     return sum;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     memset(h, -1, sizeof h);
//     for (int i = 0; i < n;i++){
//         int a, b;
//         cin >> a >> b;
//         add(a, b), add(b, a);
//     }
//     dfs(1);
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 2e5 + 10;
// int n, m;
// int h[N], e[N], ne[N], idx;
// int dist[N];
// queue<int> q;

// void add(int a,int b){
//     e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }

// int bfs(){
//     memset(dist, -1, sizeof dist);
//     q.push(1);
//     dist[1] = 0;
//     while(!q.empty()){
//         int t = q.front();
//         q.pop();
//         for (int i = h[t]; i != -1;i=ne[i]){
//             int j = e[i];
//             if(dist[j]>=0)
//                 continue;
//             dist[j] = dist[t] + 1;
//             q.push(j);
//         }
//     }
//     return dist[n];
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     memset(h, -1, sizeof h);
//     while(m--){
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//     }
//     cout<<bfs();
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 2e5 + 10;
// int n, m;
// int fa[N];

// struct Edge{
//     int a, b, w;
// } edges[N];

// bool cmp(Edge a,Edge b){
//     return a.w < b.w;
// }

// int find(int x){
//     if(fa[x]!=x)
//         fa[x] = find(fa[x]);
//     return fa[x];
// }

// int kruskal(){
//     sort(edges, edges + m, cmp);
//     for (int i = 1; i <= n;i++)
//         fa[i] = i;
//     int res = 0, cnt = 0;
//     for (int i = 0; i < m;i++){
//         int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//         a = find(a), b = find(b);
//         if(a!=b){
//             fa[a] = b;
//             res += w;
//             cnt++;
//         }
//     }
//     if(cnt<n-1)
//         return inf;
//     return res;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 0; i < m;i++){
//         int a, b, w;
//         cin >> a >> b >> w;
//         edges[i] = {a, b, w};
//     }
//     int t = kruskal();
//     if(t==inf)
//         cout << "impossible";
//     else
//         cout << t;
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <map>
// #include <set>
// #include <unordered_map>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 505;
// int n, m;
// int g[N][N];
// int dist[N];
// bool st[N];

// int prim(){
//     memset(dist, inf, sizeof dist);
//     dist[1] = 0;
//     for (int i = 0; i < n;i++){
//         int t = -1;
//         for (int j = 1; j <= n;j++){
//             if(!st[j] &&(t==-1|| dist[t]>dist[j]))
//                 t = j;
//         }
//         st[t] = 1;
//         for (int j = 1; j <= n;j++)
//             dist[j] = min(dist[j], dist[t]+g[t][j]);
//     }
//     if(dist[n]==inf)
//         return -1;
//     return dist[n];
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     memset(g, inf, sizeof g);
//     while(m--){
//         int a, b, w;
//         cin >> a >> b >> w;
//         g[a][b] = min(g[a][b], w);
//     }
//     int t = prim();
//     cout << t;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m, k;
int d[N][N];

void floyd(){
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    floyd();
    while(k--){
        int a, b;
        cin >> a >> b;
        int t = d[a][b];
        if(t>inf/2)
            cout << "impossible" << endl;
        else
            cout << t << endl;
    }
    return 0;
}
