#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULl = unsigned long long;
typedef pair<int, int> PII;
const int N = 105;
int n, m;
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
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(i==j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = min(d[a][b], w);
    }
    floyd();
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
        return 0;
}
