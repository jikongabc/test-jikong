#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 5005;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
// int t[N];
// PII pii[N];
int p[N][N];
int st[N][N];
int m;
queue<PII> q;
int t, x, y;
int bfs(){
    memset(st, -1, sizeof st);
    q.push({0, 0});
    st[0][0] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>N || b>N)
                continue;
            if(st[a][b]>=0 || st[a][b]==-2)
                continue;
            if(st[t.first][t.second]+2>=p[a][b] && p[a][b]){
                st[a][b] = -2;
                continue;
            }
            q.push({a, b});
            st[a][b] = st[t.first][t.second] + 1;
            if(!p[a][b])
                return st[a][b];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 0; i < m;i++){
    //     cin >> pii[i].first >> pii[i].second >> t[i];
    //     if (!p[pii[i].first][pii[i].second] || t[i] + 1 < p[pii[i].first][pii[i].second])
    //         p[pii[i].first][pii[i].second] = t[i] + 1;
    //     for (int j = 0; j < 4;j++){
    //         int xx = pii[i].first + dx[j], yy = pii[i].second + dy[j];
            // if(xx<0 || yy<0 || xx>N || yy>N)
            //     continue;
            // if(!p[xx][yy] || t[i]+1<p[xx][yy]){
            //     p[xx][yy] = t[i] + 1;
            // }
    //     }
    cin >> x >> y >> t;
    if(!p[x][y]|| t+1<p[x][y]){
        p[x][y] = t + 1;
    }
    for (int i = 0; i < 4;i++){
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx > N || yy > N)
            continue;
        if (!p[xx][yy] || t + 1 < p[xx][yy]){
            p[xx][yy] = t + 1;
        }
    }
    }
    int ans = bfs();
    cout << ans;
    // cout << endl;
    // for (int i = 0; i < 6;i++){
    //     for (int j = 0; j < 6;j++){
    //         cout << p[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < 6;i++){
    //     for (int j = 0; j < 6;j++){
    //         cout << st[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
        return 0;
}