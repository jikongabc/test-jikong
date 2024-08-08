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
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, k;
int s, end1;
int dist[N];
bool st[N];
int h[M], e[M], ne[M], w[M], idx;

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[s] = 0;
    q.push({0, s});
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
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    cin >> s >> end1;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        for (int j = 1; j <= k;j++){
            add(a+(j-1)*n, b + n * j, 0), add(b+(j-1)*n, a + n * j, 0);
            add(a + j * n, b + j * n, c), add(b + j * n, a + j * n, c);
        }//分层图
    }
    for (int i = 1; i <= k;i++){
        add(end1 + (i - 1) * n, end1 + i * n, 0);
    }
    dijkstra();
    //求s到e-1+n*k最短路
    cout << dist[end1 + n * k];
    return 0;
}