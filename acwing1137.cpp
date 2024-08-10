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
const int N = 1e3 + 10, M = 3e4 + 10;
int n, m, s, k;
int e[M], ne[M], w[M], h[N], idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof dist);
    q.push({0, 0});
    dist[0] = 0;
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
    if(dist[s]==inf)
        return -1;
    return dist[s];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m>>s){
        memset(h, -1, sizeof h);
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        cin >> k;
        while(k--){
            int t;
            cin >> t;
            add(0, t, 0);
        }
        
        cout << dijkstra() << endl;
    }
    return 0;
}
