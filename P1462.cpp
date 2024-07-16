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
typedef pair<LL, int> PII;
const int N = 1e4 + 10, M = 1e5 + 10;
int n, m;
LL x;
int maxn;
int f[N];
LL dist[N];
bool st[N];
int e[M], ne[M], h[M], w[M], idx;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dijkstra(int mid){
    for (int i = 1; i <= n;i++)
        dist[i] = 1e18;
    memset(st, false, sizeof st);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i] && f[j]<=mid && !st[j]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[n]<=x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        cin >> f[i];
        maxn = max(maxn, f[i]);
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==b)
            continue;
        add(a, b, c), add(b, a, c);
    }
    if(!dijkstra(1e9)){
        cout << "AFK" << endl;
        return 0;
    }
    int l = max(f[1], f[n]), r = 1e9;
    while(l<r){
        int mid = l + r >> 1;
        if(dijkstra(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}
