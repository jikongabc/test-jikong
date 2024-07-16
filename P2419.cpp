#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 205;
int n, m;
int res;
int d[N][N];

void floyd(){
    for (int k = 1; k <= n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                d[i][j] = d[i][j] || d[i][k] && d[k][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }
    floyd();
    for (int i = 1; i <= n;i++){
        int t = 1;
        for (int j = 1; j <= n;j++){
            if(i==j)
                continue;
            t = t && (d[i][j] || d[j][i]);
        }
        res += t;
    }
    cout << res;
    return 0;
}