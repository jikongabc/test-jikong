#include <iostream>
#include <sstream>
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
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<double, int> PDI;
const int N = 1e5 + 10, M = N * 10;
int a[N];
int n;
int e[M], ne[M], h[M], idx;
int dist[N];
bool st[N];

struct node{
    int a, id;
} p[M];

bool cmp(node a,node b){
    if(a.a==b.a)
        return a.id < b.id;
    return a.a < b.a;
}

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist, inf, sizeof dist);
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
            if(dist[j]>dist[ver]+1){
                dist[j] = dist[ver] + 1;
                q.push({dist[j], j});
            }
        }
    }
    return dist[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        p[i] = {a[i], i};
    }
    for (int i = 1; i < n;i++)
        add(i, i + 1);
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i < n;i++){
        if(p[i].a==p[i+1].a)
            add(p[i].id, p[i + 1].id);
    }
    cout << dijkstra();
    return 0;
}