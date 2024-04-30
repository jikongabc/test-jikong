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
typedef pair<double, int> PDI;
const int N = 10005;
int n, m;
int e[N], ne[N], h[N], w[N], idx;
int dist[N];
bool st[N];
int ans;

struct node{
    int a, b, w;
}p[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, inf, sizeof dist);
    memset(st, false, sizeof st);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        p[i] = {a, b, w};
        add(a, b, w);
    }
    dijkstra();
    for (int i = 2; i <= n;i++)
        ans += dist[i];
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++){
        int a = p[i].b, b = p[i].a, w = p[i].w;
        p[i] = {a, b, w};
        add(a, b, w);
    }
    dijkstra();
    for (int i = 2; i <= n; i++)
        ans += dist[i];
    cout << ans;
    return 0;
}