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
typedef pair<PII, int> PIII;
const int N = 1005;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, d, r;
char p[N][N];
int dist[N][N][2];
PIII q[N];

int bfs(){
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = 0;
    int res1 = inf, res2 = inf;
    q[0] = {{1, 1}, 0};
    dist[1][1][0] = 0;
    while(hh<=tt  && dist[n][m][0]==-1 && dist[n][m][1]==-1){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first.first + dx[i], b = t.first.second + dy[i];
            if(a<=0 || b<=0 || a>n || b>m)
                continue;
            if(p[a][b]!='.')
                continue;
            if(dist[a][b][t.second]>=0)
                continue;
            q[++tt] = {{a, b}, t.second};
            dist[a][b][t.second] = dist[t.first.first][t.first.second][t.second] + 1;
            if(t.second==0 && a+d>0 && a+d<=n && b+r>0 && b+r<=m && p[a+d][b+r] != '#'){
                q[++tt] = {{a + d, b + r}, 1};
                dist[a + d][b + r][1] = dist[a][b][0] + 1;
            } 
        }
    }
    if (dist[n][m][0] != -1)
        res1 = dist[n][m][0];
    if (dist[n][m][1] != -1)
        res2 = dist[n][m][1];
    return min(res1, res2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d >> r;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
        }
    }

    int res = bfs();
    if(res==inf)
        cout << -1;
    else
        cout << res;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dist[i][j][0] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dist[i][j][1] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}