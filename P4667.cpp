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
const int N = 510;
const int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
const int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};
const char ch[] = "\\/\\/";
int n, m;
char p[N][N];
int dist[N][N];
bool st[N][N];

int bfs(){
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    deque<PII> q;
    q.push_back({0, 0});
    dist[0][0] = 0;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop_front();
        if(x==n && y==m)
            return dist[x][y];
        // if(st[x][y])
        //     continue;
        st[x][y] = 1;
        for (int i = 0; i < 4;i++){
            int a = x + dx[i], b = y + dy[i];
            if(a<0 || b<0 || a>n || b>m)
                continue;
            char ia = x + ix[i], ib = y + iy[i];
            int w = (p[ia][ib] != ch[i]);
            if(dist[a][b]>dist[x][y]+w){
                dist[a][b] = dist[x][y] + w;
                if(!w)
                    q.push_front({a, b});
                else
                    q.push_back({a, b});
            }
        }
    }
    return -1;
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> p[i][j];
            }
        }
        if (n + m & 1)
            cout << "NO SOLUTION\n";
        else
            cout << bfs() << endl;
    }
    
    return 0;
}
