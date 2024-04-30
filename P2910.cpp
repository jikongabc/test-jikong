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
const int N = 105, M = 10005;
int n, m;
int p[M];
int d[N][N];

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
    cin >> n >> m;
    for (int i = 0; i < m;i++)
        cin >> p[i];
    int ans = inf;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> d[i][j];
        }
    }
    floyd();
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= n;j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    ans= d[1][p[0]] + d[p[m - 1]][n];
    for (int i = 0; i < m - 1; i++){
        ans += d[p[i]][p[i + 1]];
    }
    
    
    cout << ans;
    return 0;
}