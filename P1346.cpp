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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
const int N = 1005, M = N * N / 2;
int n, a, b;
int e[M], ne[M], h[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, inf, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, a});
    dist[a] = 0;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        int m;
        cin >> m;
        for (int j = 1; j <= m;j++){
            int v;
            cin >> v;
            int w = (j == 1) ? 0 : 1;
            add(i, v, w);
        }
    }
    int res = dijkstra();
    if(res==inf)
        cout << -1;
    else
        cout << res;
    return 0;
}