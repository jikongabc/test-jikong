#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 5005, M = 2e5 + 10;
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], dist1[N];

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    memset(dist1, 0x3f, sizeof dist1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second, dis = t.first;
        if(dis>dist1[ver])
            continue;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dis+w[i]){
                dist1[j] = dist[j];
                dist[j] = dis + w[i];
                q.push({dist[j], j});
            }
            else if(dist[j]<dis+w[i]){
                if(dist1[j]>dis+w[i]){
                    dist1[j] = dis + w[i];
                    q.push({dist1[j], j});
                }
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
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dijkstra();
    // cout << dist[n] << endl;
    cout << dist1[n];
    return 0;
}