#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 105;
int n, m;
char p[N][N];
int dist[N][N];
bool st[N][N][5][N];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int bfs(){
    dist[0][0] = 0;
    queue<pair<PII, PII>> q;
    for (int i = 0; i < 4;i++){
        q.push({{0, 0}, {i, 0}});
    }
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int x = t.first.first + dx[i], y = t.first.second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n)
                continue;
            if (p[x][y]!='.')
                continue;
            int cnt = t.second.second;
            if (t.second.first == i)
                cnt++;
            else
                cnt = 1;
            if (cnt > m)
                continue;
            if(st[x][y][i][cnt])
                continue;
            // if(dist[x][y]>=0)
            //     continue;
            dist[x][y] = dist[t.first.first][t.first.second] + 1;
            if(x==n-1 && y==n-1)
                return dist[n - 1][n - 1];
            st[x][y][i][cnt] = 1;
            q.push({{x, y}, {i,cnt}});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(dist, -1, sizeof dist);
        memset(st, 0, sizeof st);
        cin >> n >> m;
        for (int i = 0; i < n;i++)
            cin >> p[i];
        cout << bfs() << endl;
    }
    // cout << dist[n - 1][n - 1] << endl;
    return 0;
}