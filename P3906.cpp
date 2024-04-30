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
int d[N][N];
int n, m, k;

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
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = min(d[a][b], 1);
    }
    floyd();
    cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= n;i++){
            if(d[a][i]+d[i][b]==d[a][b])
                cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}