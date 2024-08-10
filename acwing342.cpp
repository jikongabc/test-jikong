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
const int N = 25010, M = 150010;
int n, m1, m2, s;
int cnt;
int h[N], e[M], ne[M], w[M], idx;
int id[N];
int din[N];
bool st[N];
int dist[N];

vector<int> block[N];
queue<int> q;

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx]= c, h[a] = idx++;
}

void dfs(int u,int cnt){
    id[u] = cnt;
    block[cnt].push_back(u);
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!id[j])
            dfs(j, cnt);
    }
}

void dijkstra(int x){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto i:block[x]){
        heap.push({dist[i], i});
    }
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j] = dist[ver] + w[i];
                if(id[ver]==id[j])
                    heap.push({dist[j], j});
                
            }
            if (id[ver] != id[j] && --din[id[j]] == 0)
                q.push(id[j]);
        }
    }
}

void topsort(){
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    for (int i = 1; i <= cnt;i++){
        if(!din[i])
            q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        dijkstra(t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m1 >> m2 >> s;
    memset(h, -1, sizeof h);
    while(m1--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= n;i++){
        if(!id[i])
            dfs(i, ++cnt);
    }
    while(m2--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        din[id[b]]++;
    }
    topsort();
    for (int i = 1; i <= n;i++){
        if(dist[i]>inf/2)
            cout << "NO PATH\n";
        else
            cout << dist[i] << endl;
    }
    return 0;
}
