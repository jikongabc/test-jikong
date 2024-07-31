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
const int N = 25;
int n, m;
int a[N][N], b[N][N];
int ans[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= m;j++){
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= m-n+1;i++){
        for (int j = 1; j <= m - n + 1;j++){
            int res = 0;
            for (int x = 1; x <= n;x++){
                for (int y = 1; y <= n;y++){
                    res += a[x][y] * b[i + x - 1][j + y - 1];
                }
            }
            ans[i][j] = res;
        }
    }
    for (int i = 1; i <= m - n + 1;i++){
        for (int j = 1; j <= m - n + 1;j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
        return 0;
}