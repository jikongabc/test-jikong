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
const int N = 5e4 + 10, M = 2e5 + 10;
int n, m;
int source[6];
int e[M], w[M], ne[M], h[N], idx;
int dist[6][N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start,int dist[]){
    memset(dist, 0x3f, N*4);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    dist[start] = 0;
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

int dfs(int u,int start,int dis){
    if (u > 5 )
        return dis;
    int res = inf;
    for (int i = 1; i <= 5;i++){
        if(!st[i]){
            int next = source[i];
            st[i] = true;
            res = min(res, dfs(u + 1, i, dis + dist[start][next]));
            st[i] = false;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    source[0] = 1;
    for (int i = 1; i <= 5;i++)
        cin >> source[i];
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 0; i < 6;i++){
        dijkstra(source[i], dist[i]);
    }
    memset(st, false, sizeof st);
    cout << dfs(1, 0, 0);
    return 0;
}
