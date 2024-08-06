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
int n, m;
int start, end1, k;
int dist[N];
bool st[N];
int h[N], rh[N], e[N], ne[N], w[N], idx;
int cnt[N];

int add(int h[],int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, end1});
    dist[end1] = 0;
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

int astar(){
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({dist[start], {0, start}});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int dis = t.second.first, ver = t.second.second;
        cnt[ver]++;
        if(cnt[end1]==k)
            return dis;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(cnt[j]<k)
                q.push({dist[j] + dis + w[i], {dis + w[i], j}});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h,-1,sizeof h);
    memset(rh, -1, sizeof rh);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(h, a, b, w), add(rh, b, a, w);
    }
    cin >> start >> end1 >> k;
    if(start==end1)
        k++;
    dijkstra();
    cout << astar();
    return 0;
}
