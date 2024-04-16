#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e6+10;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    priority_queue < PII, vector<PII>, greater<PII> > q;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second, distanse = t.first;
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
    if(dist[n]==inf)
        return -1;
    else
        return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra();
    return 0;
}