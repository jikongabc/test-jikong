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
const int N = 11, M = N * N, E = 400, P = 1 << N;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, p, k, s;
int e[E], h[M], ne[E], w[E], idx;
int ma[N][N];
int dist[M][P];
bool st[M][P];
set<PII> edges;
int key[M];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(){
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            for (int u = 0; u < 4;u++){
                int a = i + dx[u], b = j + dy[u];
                if(a<=0 || a>n || b<=0 || b>m)
                    continue;
                int x = ma[a][b], y = ma[i][j];
                if(!edges.count({x,y}))
                    add(x, y, 0), add(x, y, 0);
            }
        }
    }
}

int bfs(){
    deque<PII> q;
    memset(dist, 0x3f, sizeof dist);
    q.push_back({1, 0});
    dist[1][0] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop_front();
        if(t.first==n*m)
            return dist[t.first][t.second];
        if(st[t.first][t.second])
            continue;
        st[t.first][t.second] = 1;
        if(key[t.first]){
            int state = t.second | key[t.first];
            if (dist[t.first][state]>dist[t.first][t.second]){
                dist[t.first][state] = dist[t.first][t.second];
                q.push_front({t.first, state});
            }
        }
        for (int i = h[t.first]; ~i;i=ne[i]){
            int j = e[i];
            if(w[i] && !(t.second>>w[i]-1&1))
                continue;
            if(dist[j][t.second]>dist[t.first][t.second]+1){
                dist[j][t.second] = dist[t.first][t.second] + 1;
                q.push_back({j, t.second});
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
    cin >> n >> m >> p >> k;
    memset(h, -1, sizeof h);
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            ma[i][j] = ++cnt;
        }
    }
    while (k--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = ma[x1][y1], b = ma[x2][y2];
        edges.insert({a, b}), edges.insert({b, a});
        if(c)
            add(a, b, c), add(b, a, c);
    }
    build();
    cin >> s;
    for (int i = 0; i < s;i++){
        int x, y, c;
        cin >> x >> y >> c;
        int a = ma[x][y];
        key[a] |= 1 << c - 1;
    }
    
    cout << bfs();
    return 0;
}
