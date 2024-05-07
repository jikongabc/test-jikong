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
const int N = 505;
const int dx[] = {-1, -1, 1, 1};
const int dy[] = {-1, 1, 1, -1};
const int ix[] = {-1, -1, 0, 0};
const int iy[] = {-1, 0, 0, -1};
const char cs[] = "\\/\\/";
int n, m;
char p[N][N];
int dist[N][N];
bool st[N][N];

int bfs(){
    memset(dist, inf, sizeof dist);
    memset(st, false, sizeof st);
    deque<PII> q;
    q.push_back({0, 0});
    dist[0][0] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop_front();
        if(st[t.first][t.second])
            continue;
        st[t.first][t.second] = 1;
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || a>n || b<0 || b>m)
                continue;
            int aa = t.first + ix[i], bb = t.second + iy[i];
            int d = dist[t.first][t.second] + (p[aa][bb] != cs[i]);
            if(d<dist[a][b]){
                dist[a][b] = d;
                if(p[aa][bb]!=cs[i])
                    q.push_back({a, b});
                else
                    q.push_front({a, b});
            }
        }
    }
    return dist[n][m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> p[i][j];
            }
        }
        if ((n + m) % 2)
            cout << "NO SOLUTION\n";
        else
            cout << bfs() << endl;
    }
    return 0;
}