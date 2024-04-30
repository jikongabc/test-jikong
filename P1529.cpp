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
typedef pair<double, int> PDI;
const int N = 50005;
int T;
int dist[N];
bool st[N];
char ans;
int h[N], e[N], w[N], ne[N], idx;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, inf, sizeof dist);
    dist['Z'] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 'Z'});
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.second, distance = t.first;
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
        if (ver >= 'A' && ver < 'Z'){
            ans = ver;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> T;
    while(T--){
        char a, b;
        int w;
        cin >> a >> b >> w;
        add(a, b, w), add(b, a, w);
    }
    dijkstra();
    cout << ans << ' ' << dist[ans];
    return 0;
}