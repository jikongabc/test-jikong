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
const int N = 1010, M = 20010;
int n, m;
int e[M], ne[M], h[M], w[M], idx;
int price[N];
int dist[N][105];
bool st[N][105];
int q;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int c,int s,int end1){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({0, {s, 0}});
    dist[s][0] = 0;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int dis = t.first, ver = t.second.first, now = t.second.second;
        if(ver==end1)
            return dis;
        if(st[ver][now])
            continue;
        st[ver][now] = 1;
        if(now<c){
            if(dist[ver][now+1]>dis+price[ver]){
                dist[ver][now + 1] = dis + price[ver];
                q.push({dist[ver][now + 1], {ver, now + 1}});
            }
        }
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(now<w[i])
                continue;
            else{
                if(dist[j][now-w[i]]>dist[ver][now]){
                    dist[j][now-w[i]] = dist[ver][now];
                    q.push({dist[j][now - w[i]], {j, now - w[i]}});
                }
            }
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
    for (int i = 0; i < n;i++)
        cin >> price[i];
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    cin >> q;
    while(q--){
        int c, s, e;
        cin >> c >> s >> e;
        int res = dijkstra(c, s, e);
        if(res==-1)
            cout << "impossible\n";
        else
            cout << res << endl;
    }
        return 0;
}
