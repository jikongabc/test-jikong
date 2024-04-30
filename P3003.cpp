#include <iostream>
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
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
int n, m, s, a, b;
int h[N], e[N], ne[N], w[N], idx;
LL dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start){
    memset(st, false, sizeof st);
    memset(dist, inf, sizeof dist);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
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
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> s >> a >> b;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w), add(b, a, w);
    }
    dijkstra(s);
    int temp = min(dist[a], dist[b]);
    dijkstra(a);
    int ans = temp + dist[b];
    cout << ans;
    return 0;
}