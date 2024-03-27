#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 1005;
using LL = long long;
typedef pair<int, int> PII;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<PII> q;
int s[N][N];
int vis[N][N];
char g[N][N];
int x1, y1, x2, y2;
int n;

int bfs(){
    memset(s, -1, sizeof s);
    memset(vis, -1, sizeof vis);
    s[x1][y1] = 0, s[x2][y2] = 0;
    vis[x1][y1] = 1, vis[x2][y2] = 2;
    q.push({x1, y1});
    q.push({x2, y2});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > n)
                continue;
            if (g[a][b]!='0')
                continue;
            if(vis[a][b]+vis[t.first][t.second]==3)
                return s[t.first][t.second] + s[a][b] + 1;
            if(s[a][b]>=0)
                continue;
            s[a][b] = s[t.first][t.second] + 1;
            if(vis[a][b]==-1)
                vis[a][b] = vis[t.first][t.second];
            q.push({a, b});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> g[i] + 1;
    cin >>x1 >> y1 >> x2 >> y2;
    int ans = bfs();
    cout << ans;
    return 0;
}