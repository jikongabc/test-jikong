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
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<PII, PIII> PIIIII;
const int N = 1005, M = 1e7 + 10;
const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int n, m;
char p[N][N];
bool st[N][N][2][4];//1:x 2:y 3:used 4: ban
queue<PIIIII> q; // 1:x 2:y 4:0/1->穿没穿墙  5:ban 0/1/2/3方向 3:dist

bool pd(int x,int y,int n,int m){
    return x > 0 && x <= n && y > 0 && y <= m;
}

int bfs(){
    memset(st,false,sizeof st);    
    for (int i = 0; i < 4;i++){
        q.push({{1, 1}, {0, {0, i}}});
        st[1][1][0][i] = 1;
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first.first, y = t.first.second;
        int dis = t.second.first;
        int used = t.second.second.first;
        int ban = t.second.second.second;
        if(x==n && y==m)
            return dis;
        for (int i = 0; i < 4;i++){
            if(i==ban)
                continue;
            int a = x + dx[i], b = y + dy[i];
            if(!pd(a,b,n,m))
                continue;
            if(p[a][b]=='.'){
                if(!st[a][b][used][ban]){
                    st[a][b][used][ban] = 1;
                    q.push({{a, b}, {dis + 1, {used, ban}}});
                }
            }   
            else if(p[a][b]=='X'){
                if(!used){
                    if (!st[a][b][used][ban]){
                        st[a][b][used][ban] = 1;
                        q.push({{a, b}, {dis + 1, {1, ban}}});
                    }
                }
                else continue;
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
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
        }
    }
    cout << bfs();
    // for (int i = 1; i <= n;i++){
    //     for (int j = 1; j <= m;j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}