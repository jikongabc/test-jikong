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
const int N = 5005;
int n, m, k;
int a[105][25];
int b[101][N];

int dfs(int u, int sum)
{
    if (u == n)
        return abs(sum - k);
    if (b[u][sum] != -1)
        return b[u][sum];
    int minn = inf;
    for (int j = 0; j < m; j++)
    {
        minn = min(minn, dfs(u + 1, sum + a[u][j]));
    }
    b[u][sum] = minn;
    return minn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> k;
    memset(b, -1, sizeof b);
    int res = dfs(0, 0);
    cout << res << endl;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
        return 0;
}
