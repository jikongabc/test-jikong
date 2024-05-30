#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
int pa, pb, ps;
int a, b, n, m;
const int N = 1e5 + 10;
int dist[N];
int dist1[N], dist2[N], dist3[N];

int e[N], ne[N], h[N], idx;
int q[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs1(){
    memset(dist1, -1, sizeof dist1);
    int hh = 0, tt = 0;
    q[0] = a;
    dist1[a] = 0;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist1[j]>=0)
                continue;
            dist1[j] = dist1[t] + 1;
            q[++tt] = j;
        }
    }
}
void bfs2(){
    memset(dist2, -1, sizeof dist2);
    int hh = 0, tt = 0;
    q[0] = b;
    dist2[b] = 0;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist2[j]>=0)
                continue;
            dist2[j] = dist2[t] + 1;
            q[++tt] = j;
        }
    }
}
void bfs3(){
    memset(dist3, -1, sizeof dist3);
    int hh = 0, tt = 0;
    q[0] = n;
    dist3[n] = 0;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist3[j]>=0)
                continue;
            dist3[j] = dist3[t] + 1;
            q[++tt] = j;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> pa >> pb >> ps;
    cin >> a >> b >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    int res = inf;
    bfs1();
    bfs2();
    bfs3();
    for (int i = 1; i <= n;i++){
        int cnt = dist1[i] * pa + dist2[i] * pb + dist3[i] * (pa + pb - ps);
        if(dist1[i]==-1 || dist2[i]==-1 || dist3[i]==-1)
            continue;
        res = min(res, cnt);
    }
    if(res==inf){
        cout << -1;
        return 0;
    }
    cout << res;
    return 0;
}