#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 50;

struct node{
    int first;
    int second;
    int third;
};

char p[N][N][N];
int st[N][N][N];

int dh[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};

queue<node> q;
int n, m, h;
int h1, x1, y1;
int h2, x2, y2;

int bfs(){
    memset(st, -1, sizeof st);
    q.push({h1, x1, y1});
    st[h1][x1][y1] = 0;
    if(h1==h2 && x1==x2 && y1==y2)
        return 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 6;i++){
            int a = t.first + dh[i], b = t.second + dx[i], c = t.third + dy[i];
            if(a<0 || b<0 || c<0 || a>=h || b>=n || c>=m)
                continue;
            if(p[a][b][c]=='#')
                continue;
            if(st[a][b][c]>=0)
                continue;
            st[a][b][c] = st[t.first][t.second][t.third] + 1;
            q.push({a, b, c});
            // cout << a << ' ' << b << ' ' << c << endl;
            // cout << st[a][b][c] << endl;
            if (a == h2 && b == x2 && c == y2)
                return st[a][b][c];
        }
    }
    return -1;
}
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    while(cin >> h >> n >> m){
        if(!h && !n && !m)
            break;
        while(!q.empty()){
            q.pop();
        }
        for (int i = 0; i < h; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < m; k++){
                    cin >> p[i][j][k];
                    if (p[i][j][k] == 'S'){
                        h1 = i, x1 = j, y1 = k;
                    }
                    if (p[i][j][k] == 'E'){
                        h2 = i, x2 = j, y2 = k;
                    }
                }
            }
        }
        int ans = bfs();
        // cout << h2 << ' ' << x2 << ' ' << y2;
        if (ans == -1)
            cout << "Trapped!\n";
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}