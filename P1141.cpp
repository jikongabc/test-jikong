#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef pair <int, int> PII;
typedef long long LL;
const int N = 1005;
char p[N][N];
int st[N][N];
int arr[N][N];
int n, m;
queue<PII> q;
vector<PII> v;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(int x,int y){
    // memset(st, 0, sizeof st);
    q.push({x, y});
    v.push_back({x, y});
    st[x][y] = 1;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a > 0 && b > 0 && a <= n && b <= n && !st[a][b] && p[a][b]!=p[t.first][t.second]){
                q.push({a, b});
                v.push_back({a, b});
                st[a][b] = 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> p[i][j];
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(!st[i][j]){
                q.empty();
                v.clear();
                st[i][j] = 1;
                bfs(i, j);
                for (vector<PII>::iterator it = v.begin(); it != v.end();it++){
                    arr[(*it).first][(*it).second] = v.size();
                }
            }
        }
    }
        while (m--)
        {
            int o, p;
            int count = 0;
            cin >> o >> p;
            // bfs(o, p);
            // for (int i = 1; i <= n;i++){
            //     for (int j = 1; j <= n;j++){
            //         if(st[i][j]==1)
            //             count++;
            //     }
            // }
            cout <<arr[o][p] <<'\n';
        }
    return 0;
}