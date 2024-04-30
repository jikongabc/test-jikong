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
typedef pair<double, int> PDI;
const int N = 105;
int n;
int d[N][N];
int a[N];
int m;

void floyd(){
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> d[i][j];
        }
    }
    cin >> m;
    for (int i = 0; i < m;i++){
        cin >> a[i];
    }
    floyd();
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= n;j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = inf;
    do{
        int res = d[1][a[0]] + d[a[m - 1]][n];
        for (int i = 0; i < m; i++){
            ans += d[a[i]][a[i + 1]];
        }
        ans = min(ans, res);
    } while (next_permutation(a, a + m));
    cout << ans;
    return 0;
}