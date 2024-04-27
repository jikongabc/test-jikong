#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#define ingf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 1005;
int n, m;
int cnt;
char p[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int x,int y){
    bool st[N][N] = {0};
    st[x][y] = 1;
    queue<PII> q;
    q.push({x, y});
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m)
                continue;
            if (st[a][b])
                continue;
            if (p[a][b] != '#')
                cnt++;
            st[a][b] = 1;
            if (p[a][b] != '#' && p[a][b] != '$')
            {
                q.push({a, b});
            }
    }
    }
    // cnt++;
    // for (int i = 0; i < 4;i++){
    //     int a = x + dx[i], b = y + dy[i];
    //     if(a<0 || b<0 || a>=n || b>=m)
    //         continue;
    //     if(st[a][b])
    //         continue;
    //     if(p[a][b]!='#')
    //         cnt++;
    //     st[a][b] = 1;
    //     if(p[a][b]!='#' && p[a][b]!='$'){
    //         dfs(a, b);
    //     }
    // }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool pd = 0;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
            if(p[i][j]!='#')
                pd = 1;
        }
    }
    if(!pd){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if (p[i][j] == '#')
            {
                for (int k = 0; k < 4; k++)
                {
                    int aa = i + dx[k], bb = j + dy[k];
                    if (aa < 0 || bb < 0 || aa >= n || bb >= m)
                        continue;
                    if (p[aa][bb] == '.')
                        p[aa][bb] = '$';
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
            if(p[i][j]=='.' ){
                cnt = 1;
                bfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;

    return 0;
}