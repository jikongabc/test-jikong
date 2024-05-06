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
const int N = 155, M = N * N;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int x1, y1, x2, y2;
int dist[N][N];
PII q[M];
string p[N];

int bfs(){
    int hh = 0, tt = 0;
    memset(dist, -1, sizeof dist);
    q[0] = {x1, y1};
    dist[x1][y1] = 0;
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 8;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=m)
                continue;
            if(dist[a][b]>=0)
                continue;
            if(p[a][b]=='*')
                continue;
            q[++tt] = {a, b};
            dist[a][b] = dist[t.first][t.second] + 1;
        }
    }
    return dist[x2][y2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
            if(p[i][j]=='K')
                x1 = i, y1 = j;
            else if(p[i][j]=='H')
                x2 = i, y2 = j;
        }
    }
    cout << bfs();
    return 0;
}