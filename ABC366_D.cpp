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

const int N = 105;

int a[N][N][N];
int pre[N][N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                cin >> a[i][j][k];
                pre[i][j][k] = 0; 
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                pre[i][j][k] = a[i][j][k] + pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] - pre[i - 1][j - 1][k] - pre[i - 1][j][k - 1] - pre[i][j - 1][k - 1] + pre[i - 1][j - 1][k - 1];
            }
        }
    }
    int q;
    cin >> q;
    while (q--){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        int res = pre[rx][ry][rz] - pre[lx - 1][ry][rz] - pre[rx][ly - 1][rz] - pre[rx][ry][lz - 1] + pre[lx - 1][ly - 1][rz] + pre[lx - 1][ry][lz - 1] + pre[rx][ly - 1][lz - 1] - pre[lx - 1][ly - 1][lz - 1];
        cout << res << endl;
    }

    return 0;
}
