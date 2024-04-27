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
const int N =100010;
int n, m, k;
int h[N], w[N], e[N], ne[N], idx;
int ans[N];
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

struct{
    int a, b, w;
} p[N];

void dijkstra(){
    // int res = 0;
    memset(dist, inf, sizeof dist);
    dist[k] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, k});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second, distance = t.first;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    // for (int i = 0; i < n;i++){
    //     int t = -1;
    //     for (int j = 1; j <= n;j++){
    //         if(!st[j] &&(t==-1|| dist[t]>dist[j]))
    //             t = j;
    //     }
    //     st[t] = 1;
    //     for (int j = 1; j <= n;j++){
    //         dist[j] = min(dist[j], dist[t] + g[t][j]);
    //         // res = max(res, dist[j]);
    //     }
    // }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        p[i] = {a, b, w};
        // g[a][b]= min(g[a][b], w);
        add(a, b, w);
    }
    dijkstra();
    memcpy(ans, dist,sizeof dist);
    // memset(g, inf, sizeof g);
    memset(h, -1, sizeof h);
    memset(st, false, sizeof st);
    for (int i = 0; i < m;i++){
        int a = p[i].b, b = p[i].a, w = p[i].w;
        // g[a][b] = min(g[a][b], w);
        add(a, b, w);
    }
    dijkstra();
    int res = 0;
    for (int i = 1; i <= n;i++){
        ans[i] = ans[i] + dist[i];
        res = max(res, ans[i]);
    }
    cout << res;
    // for (int i = 1; i <= n; i++)
    //     cout << dist[i] << endl;
    return 0;
}