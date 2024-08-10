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
const int N = 1e3 + 10, M = 1e4 + 10;
int n, m;
int s, f;
int h[N], e[M], ne[M], w[M], idx;
int dist[N][2];
int cnt[N][2];
bool st[N][2];

struct node{
    int ver, type, dis;
    bool operator > (const node &W) const{
        return dis > W.dis;
    }
};

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijksta(int start,int end1){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    memset(cnt, 0, sizeof cnt);
    priority_queue<node, vector<node>, greater<node>> q;
    q.push({start, 0, 0});
    dist[start][0] = 0;
    cnt[start][0] = 1;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int ver = t.ver, dis = t.dis, type = t.type;
        if(st[ver][type])
            continue;
        st[ver][type] = 1;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j][0]>dis+w[i]){
                dist[j][1] = dist[j][0];
                cnt[j][1] = cnt[j][0];
                q.push({j, 1, dist[j][1]});
                dist[j][0] = dis + w[i];
                cnt[j][0] = cnt[ver][type];
                q.push({j, 0, dist[j][0]});
            }
            else if(dist[j][0]==dis+w[i]){
                cnt[j][0] += cnt[ver][type];
            }
            else if(dist[j][1]>dis+w[i]){
                dist[j][1] = dis + w[i];
                cnt[j][1] += cnt[ver][type];
                q.push({j, 1, dist[j][1]});
            }
            else if(dist[j][1]==dis+w[i]){
                cnt[j][1] += cnt[ver][type];
            }
        }
    }
    return dist[end1][0] + 1 == dist[end1][1] ? cnt[end1][0] + cnt[end1][1] : cnt[end1][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(h, -1, sizeof h);
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        cin >> s >> f;
        cout << dijksta(s, f) << endl;
    }
    return 0;
}
