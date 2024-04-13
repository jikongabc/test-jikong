#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 20;
int dx[] = {-1, -1,0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int biao[] = {0, 1, 2, 3, 4, 5, 6, 7};
int n, k;
int p[N][N];
bool st[N][N];
int ans[N];
bool pd = 0;
void dfs(int x, int y, int cnt){
    if(pd)
        return;
    if(x==n-1 && y==n-1){
        bool judge = 0;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                if(!st[i][j]){
                    judge = 1;
                    break;
                }
            }
        }
        if(!judge){
            pd = 1;
            for (int i = 0; i < cnt;i++){
                cout << ans[i];
            }
        }
        return;
    }

    for (int i = 0; i < 8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=n )
            continue;
        if(st[a][b])
            continue;
        if(p[x][y]==k-1){
            if(p[a][b]==0){
                ans[cnt] = biao[i];
                st[a][b] = 1;
                dfs(a, b, cnt + 1);
                st[a][b] = 0;
            }
        }
        if(p[x][y]<k-1){
            if(p[a][b]==p[x][y]+1){
                ans[cnt] = biao[i];
                st[a][b] = 1;
                dfs(a, b, cnt + 1);
                st[a][b] = 0;
            }
        }
        
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> p[i][j];
        }
    }
    st[0][0] = 1;
    dfs(0, 0, 0);
    return 0;
}