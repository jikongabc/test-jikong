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
const int N = 55, M = N * N + 10;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n, m;
int p[N][N];
bool st[N][N];
PII q[M];
int cnt, res;

int bfs(int x,int y){
    int hh = 0, tt = 0;
    int res = 1;
    q[0] = {x, y};
    st[x][y] = 1;
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=m)
                continue;
            if(st[a][b])
                continue;
            if(p[t.first][t.second]>>i&1)
                continue;
            res++;
            q[++tt] = {a, b};
            st[a][b] = 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(!st[i][j]){
                res = max(res, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << endl
         << res;
    return 0;
}