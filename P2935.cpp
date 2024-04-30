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
const int N = 505, M = 1e6 + 10;
int d[N][N];
int n,m,k;
int p[M];
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
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j)
                d[i][j]= 0;
            else
                d[i][j] = inf;
        }
    }
    while (k--){
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min(d[a][b], w);
    }
    floyd();
    int sum = inf;
    int ans;
    for (int i = 1; i <= n;i++){
        int res = 0;
        for (int j = 0; j < m;j++){
            res += d[i][p[j]];
        }
        if(res<sum){
            sum = res;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}