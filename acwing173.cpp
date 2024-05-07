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
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
const int N = 1005, M = N * N;
int n, m;
char p[N][N];
int dist[N][N];
PII q[M];
int hh, tt = -1;
int dis(int x1,int y1,int x2,int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
            if(p[i][j]=='1'){
                dist[i][j] = 0;
                q[++tt] = {i, j};
            }
        }
    }
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=m)
                continue;
            if(dist[a][b]>=0)
                continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}