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
const int N = 300;
int n, m;
int p[N][N];
bool st[N][N];
queue<PII> q;
map<int, int> ma;
int ans;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int x,int y){
    ans++;
    st[x][y] = 1;
    q.push({x, y});
    int cnt = 1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=m)
                continue;
            if(st[a][b])
                continue;
            if(!p[a][b])
                continue;
            st[a][b] = 1;
            q.push({a, b});
            cnt++;
        }
    }
    if(ma[cnt])
        ma[cnt]++;
    else
        ma[cnt] = 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m){
        if(!m && !n )
            break;
    // cin >> n >> m;
    ans = 0;
    ma.clear();
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> p[i][j];
        }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                if(p[i][j] && !st[i][j]){
                    bfs(i, j);
                }
            }
        }
    map<int, int>::iterator it;
    cout << ans << endl;
    for (it = ma.begin(); it != ma.end();it++){
        cout << it->first << ' ' << it->second << endl;
    }
    }

    return 0;
}