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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 1005, M = N * N ;
int n, m;
char p[N][N];
int dist[N][N];
map<int, PII> ma;
int k;
int fa[M];
int cnt;

struct Edge{
    int a, b, w;
} edges[M];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    int res = 0;
    sort(edges, edges + cnt, cmp);
    for (int i = 0; i < k;i++)
        fa[i] = i;
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res += w;
        }
    }
    return res;
}

void bfs(int x,int y){
    PII q[M];
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = 0;
    q[0] = {x, y};
    dist[x][y] = 0;
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || b<=0 || a>n || b>m)
                continue;
            if(p[a][b]=='#')
                continue;
            if (dist[a][b] != -1)
                continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
            if(p[i][j]=='*')
                ma[k++] = {i, j};
        }
    }
    for (int i = 0; i < k-1;i++){
        for (int j = i + 1; j < k;j++){
            bfs(ma[i].first, ma[i].second);
            edges[cnt++] = {i, j, dist[ma[j].first][ma[j].second]};
            if(dist[ma[j].first][ma[j].second]<=0){
                cout << "No";
                return 0;
            }
        }
    }
    int t=kruskal();
    if(t<0)
        cout << "No";
    else
        cout << t;
    return 0;
}