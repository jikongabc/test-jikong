#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 1e6 + 10;
int n, k;
int e[N], h[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a,int b){
    e[idx] = b, w[idx] = 1, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, inf, sizeof dist);
    dist[1] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
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
    if(dist[k]==inf)
        return -1;
    return dist[k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    if(k==1){
        cout << 0;
        return 0;
    }
    cout << dijkstra();
    return 0;
}