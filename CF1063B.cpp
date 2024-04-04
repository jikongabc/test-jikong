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
typedef pair<int, int> PII;
const int N = 2005;
int n, m;
int x1, y1;
int ll, rr;
char ch[N][N];
int dist[N][N];
queue<PII> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans;

void bfs(){
    memset(dist, -1, sizeof dist);
    q.push({x1, y1});
    dist[x1][y1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || b<=0 || a>n || b>m)
                continue;
            if(ch[a][b]!='.')
                continue;
            if(dist[a][b]!=-1 && dist[a][b]<=dist[t.first][t.second]+(i==3) )
                continue;
            dist[a][b] = dist[t.first][t.second] + (i == 3);
            q.push({a, b});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x1 >> y1 >> ll >> rr;
    for (int i = 1; i <= n;i++){
        cin >> ch[i]+1;
    }
    bfs();
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(dist[i][j]==-1)
                continue;
            int xx = dist[i][j], yy = j - y1 + xx;
            if(xx<=ll && yy<=rr)
                ans++;
        }
    }
    cout << ans;
    return 0;
}