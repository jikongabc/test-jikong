#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULl = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 1000010;
int n, m;
int x, y;
int h[N], e[N], ne[N], idx;
double w[N];
double dist[N];
bool st[N];

void add(int a,int b,double c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0, sizeof dist);
    dist[x] = 1.0;
    priority_queue<PDI> q;
    q.push({1.0, x});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
        double distance = t.first;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1;i=ne[i]){
            int j = e[i];
            if(dist[j]<dist[ver]*w[i]){
                dist[j] = dist[ver] * w[i];
                if(!st[j])
                    q.push({dist[j], j});
            }
        }
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        double w;
        cin >> a >> b >> w;
        w = 1.0 - (double)(w / 100);
        add(a, b, w), add(b, a, w);
    }
    cin >> x >> y;
    dijkstra();
    // for (int i = 1; i <= n;i++)
    //     cout << dist[i] << endl;
        printf("%.8lf", 100/dist[y]);
        return 0;
}