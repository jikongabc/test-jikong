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
typedef pair<int, PII> PIII;
const int N = 2e4 + 10;
int n, m, k;
int dist[N];
bool st[N];
int cnt[N];
int h[N], rh[N], e[N], ne[N], w[N], idx;
int res;

void add(int h[],int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
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
        for (int i = rh[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});
            }
        }
    }
}

void astar(){
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({dist[n], {0, n}});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int dis = t.second.first, ver = t.second.second;
        cnt[ver]++;
        if(ver==1){
            cout << dis << endl;
            res++;
        }
        if(cnt[1]>k)
            break;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(cnt[j]<=k)
                q.push({dist[j] + dis + w[i], {dis + w[i], j}});
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c), add(rh, b, a, c);
    }
    dijkstra();
    astar();
    // for (int i = 1; i <= n;i++)
    //     cout << dist[i] << endl;
    k -= res;
    while(k--)
        cout << -1 << endl;
    return 0;
}
