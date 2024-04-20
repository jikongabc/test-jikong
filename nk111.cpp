#include <iostream>
#include <algorithm>
#include <cstring>
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
const int N = 505;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
bool d[] = {0, 1, 0, 1};
int p[N][N];
int n, m, k;
queue<PII> q;
int st[N][N];
int dist[N][N];
int xx[N][N];
int yy[N][N];
void bfs(int x, int y)
{
    memset(st, -1, sizeof st);
    memset(xx, -1, sizeof xx);
    memset(yy, -1, sizeof yy);
    q.push({x, y});
    st[x][y] = 0;
    xx[x][y] = 0;
    yy[x][y] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (d[i])
            {
                xx[a][b] = xx[t.first][t.second] + 1;
                yy[a][b] = yy[t.first][t.second];
            }
            else
            {
                xx[a][b] = xx[t.first][t.second];
                yy[a][b] = yy[t.first][t.second] + 1;
            }
            if (st[a][b] >= 0)
                continue;
            if (a <= 0 || b <= 0 || a > n || b > m)
                continue;
            st[a][b] = st[t.first][t.second] + 1;
            
            q.push({a, b});
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == n / 2 + 1 && j == m / 2 + 1)
                dist[i][j] = inf;
            else
                dist[i][j] = min({i, j, n - i + 1, m - j + 1});
        }
    }
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    bfs(n / 2 + 1, m / 2 + 1);
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << st[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int ans = 0;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (xx[a][b] <= dist[a][b] && yy[a][b] <= dist[a][b])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}