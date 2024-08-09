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
const int N = 55;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
int x0, y0, xe, ye;

int p[N][N];
int dist[N][N][4];
queue<PIII> q;
char c;
int cc;
string op = "NESW";

bool pd(int x, int y)
{
    if (x <= 0 || y <= 0 || x >= n || y >= m)
        return false;
    if (p[x][y] == 1 || p[x + 1][y] == 1 || p[x][y + 1] == 1 || p[x + 1][y + 1] == 1)
        return false;
    return true;
}

int bfs()
{
    memset(dist, -1, sizeof dist);
    q.push({{x0, y0}, cc});
    dist[x0][y0][cc] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t.first.first, y = t.first.second, ip = t.second;
        for (int i = 1; i <= 3; i++)
        {
            int a = x + dx[ip] * i, b = y + dy[ip] * i;
            if(!pd(a,b))
                break;
            if (pd(a, b) && dist[a][b][ip] == -1)
            {
                dist[a][b][ip] = dist[x][y][ip] + 1;
                if (a == xe && b == ye)
                {
                    return dist[a][b][ip];
                }
                q.push({{a, b}, ip});
            }
        }
        int ip1 = (ip - 1 + 4) % 4;
        if (dist[x][y][ip1] == -1)
        {
            dist[x][y][ip1] = dist[x][y][ip] + 1;
            q.push({{x, y}, ip1});
        }
        int ip2 = (ip + 1) % 4;
        if (dist[x][y][ip2] == -1)
        {
            dist[x][y][ip2] = dist[x][y][ip] + 1;
            q.push({{x, y}, ip2});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
        }
    }
    cin >> x0 >> y0 >> xe >> ye >> c;
    for (int i = 0; i < 4; i++)
    {
        if (c == op[i])
            cc = i;
    }
    cout << bfs();
    // cout << endl;
    // for (int i = 1; i <= 3;i++){
    //     for (int j = 0; j <= n;j++){
    //         for (int k = 0; k <= m;k++){
    //             cout << dist[i][j][i] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    //     cout << endl;
    // }
    return 0;
}