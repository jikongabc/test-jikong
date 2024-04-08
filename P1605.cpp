#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 25;
int n, m, t;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int x1, y1, x2, y2, xx, yy;
int p[N][N];
int ans;

void dfs(int x,int y){
    if(x==x2 && y==y2){
        ans++;
        return;
    }
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<=0 || b<=0 || a>n || b>m)
            continue;
        if(p[a][b])
            continue;
        p[x][y] = 1;
        dfs(a, b);
        p[x][y] = 0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    cin >> x1 >> y1 >> x2 >> y2;
    while(t--){
        cin >> xx >> yy;
        p[xx][yy] = 1;
    }
    dfs(x1, y1);
    cout << ans;
    return 0;
}
