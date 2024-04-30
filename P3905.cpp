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
int n, m, k;
int d[N][N];
bool st[N][N];
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
            if(i==j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
    cin >> m;
    for (int i = 0; i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min(d[a][b], w);
    }
    cin >> k;
    for (int i = 0; i < k;i++){
        int a, b, w;
        cin >> a >> b;
        st[a][b] = st[b][a] = 1;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(!st[i][j] && d[i][j]!=inf)
                d[i][j] = 0;
        }
    }
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= n;j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    floyd();
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int a, b;
    cin >> a >> b;
    cout << d[a][b];
    return 0;
}