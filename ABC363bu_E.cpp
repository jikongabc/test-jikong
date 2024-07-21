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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1010, M = 1e5 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
int w;
int a[N][N];
priority_queue<PIII, vector<PIII>, greater<PIII>> q;
bool st[N][N];
bool sst[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> w;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    int res = n * m;
    for (int i = 1; i <=n ;i++){
        for (int j = 1; j <= m;j++){
            if(i==1|| j==1 || i==n || j==m){
                q.push({a[i][j], {i, j}});
                sst[i][j] = 1;
            }
        }
    }
        for (int i = 1; i <= w; i++)
        {
            while (q.top().first <= i && q.size())
            {
                auto t = q.top();
                q.pop();
                int x = t.second.first, y = t.second.second;
                if(st[x][y])
                    continue;
                st[x][y] = 1;
                res--;
                // cout << x << ' ' << y << endl;
                // sst[x][y] = 0;
                for (int j = 0; j < 4; j++)
                {
                    int xx = x + dx[j], yy = y + dy[j];
                    if (xx <= 0 || yy <= 0 || xx > n || yy > m)
                        continue;
                    if (st[xx][yy] || sst[xx][yy])
                        continue;
                    sst[xx][yy] = 1;
                    q.push({a[xx][yy], {xx, yy}});
                }
            }
            cout << res << endl;
            // cout << endl;
        }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << st[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << sst[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

        return 0;
}