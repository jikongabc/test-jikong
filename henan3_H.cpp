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
typedef pair<int, PII> PIII;
typedef pair < int, pair<int, pair<int, int>> PIIII;
const int N = 55;
const int M = 1005;
int p[N][N];
int st[N][N][M];
int d[2][2] = {{0, 1}, {1, 0}};

int main()
{
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> p[i][j];
    priority_queue<PIII>, vector<PIII>>, greater<PIII>> q;
    q.push({0, {0, {h, 0}}});

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k <= h; ++k)
                st[i][j][k] = INT_MAX;

    st[0][0][h] = 0;

    while (!q.empty())
    {
        auto [cur_magic, cur_state] = q.top();
        auto [cur_x, cur_others] = cur_state;
        auto [cur_health, cur_y] = cur_others;
        q.pop();

        if (cur_x == n - 1 && cur_y == m - 1)
        {
            cout << cur_magic << endl;
            return 0;
        }

        for (const auto &dir : d)
        {
            int nx = cur_x + dir[0];
            int ny = cur_y + dir[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                int new_health = cur_health - p[nx][ny];
                if (new_health > 0 && cur_magic < st[nx][ny][new_health])
                {
                    st[nx][ny][new_health] = cur_magic;
                    q.push(make_pair(cur_magic, make_pair(nx, make_pair(new_health, ny))));
                }
                if (cur_magic + 1 < st[nx][ny][cur_health])
                {
                    st[nx][ny][cur_health] = cur_magic + 1;
                    q.push(make_pair(cur_magic + 1, make_pair(nx, make_pair(cur_health, ny))));
                }
            }
        }
    }

    return 0;
}
