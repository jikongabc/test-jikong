#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 105;
int n, m, k, q;
LL e[N][N];
LL d[N][N];
LL temp[N][N];

void floyd(){
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++)
                temp[i][j] = min(temp[i][j], d[i][k] + e[k][j]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
        }
    }
    while (m--){
        LL a, b, w;
        cin >> a >> b >> w;
        e[a][b] = min(e[a][b], w);
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <=n;j++){
            d[i][j] = e[i][j];
        }
    }
    cin >> k >> q;
    k = min(k, n);
    for (int p = 2; p <= k;p++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                temp[i][j] = d[i][j];
            }
        }
        floyd();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = temp[i][j];
            }
        }
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        if(d[a][b]==inf)
            cout << -1 << endl;
        else if(a==b)
            cout << 0 << endl;
        else
            cout << d[a][b] << endl;
    }
    return 0;
}