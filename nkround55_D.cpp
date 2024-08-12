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
const int N = 1e3 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n;
int p[N][N];
int dist[N][N];

void bfs(){
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push({1, 1});
    dist[1][1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>n+1 || b>n+1)
                continue;
            // 左
            if (p[a][b] == 1 && i == 3 || b == 0)
            {
                int tx = a, ty = b + 1;
                // cout << "--" << tx << "--" << ty << endl;
                while (p[tx][ty] == 0 && ty <= n)
                    ty++;
                if (dist[tx][ty - 1] == -1)
                {
                    dist[tx][ty - 1] = dist[t.first][t.second] + 1;
                    q.push({tx, ty - 1});
                }
                // cout << "--"<<tx <<"--"<<ty << endl;
            }
            // 上
            if(p[a][b]==1 && i==0 || a==0)
            {
                int tx = a + 1, ty = b;
                while(p[tx][ty]==0 && tx<=n)
                    tx++;
                if(dist[tx-1][ty]==-1)
                {
                    dist[tx - 1][ty] = dist[t.first][t.second] + 1;
                    q.push({tx - 1, ty});
                }
            }
            // 右
            if (p[a][b] == 1 && i == 1 || b==n+1)
            {
                int tx = a, ty = b - 1;
                while (p[tx][ty] == 0 && ty >= 1)
                    ty--;
                if (dist[tx][ty + 1] == -1)
                {
                    dist[tx][ty + 1] = dist[t.first][t.second] + 1;
                    q.push({tx, ty + 1});
                }
            }

            // 下
            if (p[a][b] == 1 && i == 2 || a==n+1)
            {
                int tx = a - 1, ty = b;
                while (p[tx][ty] == 0 && tx >= 1)
                    tx--;
                if (dist[tx + 1][ty] == -1)
                {
                    dist[tx + 1][ty] = dist[t.first][t.second] + 1;
                    q.push({tx + 1, ty});
                }
            }

            if(p[a][b]==0 && dist[a][b]==-1 && a>0 && b>0 && a<=n && b<=n){
                dist[a][b] = dist[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> p[i][j];
        }
    }
    bfs();
    cout << dist[n][n];
    // cout << endl;
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= n;j++){
    //         if(dist[i][j]>=0)
    //             cout << ' ';
    //         cout << dist[i][j] << ' ';
    //     }
            
    //     cout << endl;
    // }
        return 0;
}
