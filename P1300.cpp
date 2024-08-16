#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
const int N = 35;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
int xn, yn;
char p[N][N];
int dist[N][N][4];//1:x 2:y 3: 怎么走过来的
queue<PIII> q;

void bfs(){
    while(!q.empty()){
        auto t= q.front();
        q.pop();
        int x = t.first.first, y = t.first.second, op = t.second;
        // if(x==xn && y==yn){
        //     return dist[x][y][op];
        // } 
        int op1 = (4 + op - 1) % 4; //左转
        bool flag = false;
        int a = x + dx[op1], b = y + dy[op1];
        if(a>0 && b>0 && a<=n && b<=m && p[a][b]!='.' && (dist[x][y][op]+1<=dist[a][b][op1])){
            q.push({{a, b}, op1});
            dist[a][b][op1] = dist[x][y][op] + 1;
            flag = true;
        } 
        int op2 = (op + 1) % 4; //右转
        a = x + dx[op2], b = y + dy[op2];
        if (a > 0 && b > 0 && a <= n && b <= m && p[a][b] != '.' && (dist[x][y][op] + 5 <= dist[a][b][op2]))
        {
            q.push({{a, b}, op2});
            dist[a][b][op2] = dist[x][y][op] + 5;
            flag = true;
        }
        a = x + dx[op], b = y + dy[op];
        if (a > 0 && b > 0 && a <= n && b <= m && p[a][b] != '.' && (dist[x][y][op] <= dist[a][b][op]))
        {
            q.push({{a, b}, op});
            dist[a][b][op] = dist[x][y][op];
            flag = true;
        }
        int op3 = (op + 2) % 4; // 掉头
        a = x + dx[op3], b = y + dy[op3];
        if (a > 0 && b > 0 && a <= n && b <= m && p[a][b] != '.' && (dist[x][y][op] + 10 <= dist[a][b][op3]) && !flag)
        {
            q.push({{a, b}, op3});
            dist[a][b][op3] = dist[x][y][op] + 10;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dist,0x3f,sizeof dist);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
            if(p[i][j]=='N'){
                q.push({{i, j}, 0});
                dist[i][j][0] = 0;
            }
            else if(p[i][j]=='E'){
                q.push({{i,j},1});
                dist[i][j][1] = 0;
            }
            else if(p[i][j]=='S'){
                q.push({{i, j}, 2});
                dist[i][j][2] = 0;
            }
            else if(p[i][j]=='W'){
                q.push({{i, j}, 3});
                dist[i][j][3] = 0;
            }
            else if(p[i][j]=='F'){
                xn = i, yn = j;
            }
        }
    }
    bfs();
    int res = inf;
    for (int i = 0; i < 4;i++){
        if (~dist[xn][yn][i]){
            res = min(res, dist[xn][yn][i]);
        }
    }
    cout << res;
    return 0;
}
