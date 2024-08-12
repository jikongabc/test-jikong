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
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];
int pos[N][N];
int path[N];
int cnt;

void get_path(int i,int j){
    if(!pos[i][j])
        return;
    int k = pos[i][j];
    get_path(i, k);
    path[cnt++] = k;
    get_path(k, j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n;i++)
        g[i][i] = 0;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    memcpy(d, g, sizeof d);
    int res = inf;
    for (int k = 1; k <= n;k++){
        for (int i = 1; i < k;i++){
            for (int j = i + 1; j < k;j++){
                if((LL)(d[i][j]+g[j][k]+g[k][i])<res){
                    res = d[i][j] + g[j][k] + g[k][i];
                    cnt = 0;
                    path[cnt++] = j;
                    path[cnt++] = k;
                    path[cnt++] = i;
                    get_path(i, j);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
            }
        }
    }
    if(res==inf){
        cout << "No solution.";
        return 0;
    }
    else {
        for (int i = 0; i < cnt; i++)
            cout << path[i] << ' ';
    }
        return 0;
}
