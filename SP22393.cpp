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
const int N = 1e3 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
char p[N][N];
int dist[N][N];

int bfs(){
    memset(dist, 0x3f, sizeof dist);
    deque<PII> q;
    q.push_back({1, 1});
    dist[1][1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop_front();
        if(t.first==n && t.second==m)
            return dist[n][m];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || a>n|| b<=0 || b>m)
                continue;
            if(p[a][b]==p[t.first][t.second]){
                if(dist[a][b]>dist[t.first][t.second]){
                    dist[a][b] = dist[t.first][t.second];
                    q.push_front({a, b});
                }
            }
            else{
                if(dist[a][b]>dist[t.first][t.second]+1){
                    dist[a][b] = dist[t.first][t.second] + 1;
                    q.push_back({a, b});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                cin >> p[i][j];
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}
