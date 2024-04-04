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
const int N = 1005;
int n, m;
int p[N][N];
int st[N][N];
int num[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, -1, 0, 1, -1, 1, -1, 0};
int bv3;
int cnt;

void init(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (p[i][j] == 1){
                num[i][j] = -1;
                for (int k = 0; k < 8; k++){
                    int xx = i + dx[k], yy = j + dy[k];
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m)
                        continue;
                    if (p[xx][yy] == 1)
                        continue;
                    if (num[xx][yy])
                        continue;
                    num[xx][yy] = 1;
                }
            }
        }
    }
}

void cnt_bv3_num(){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            int judge = 1;
            if(num[i][j]>0){
                for (int k = 0; k < 8;k++){
                    int aa = i + dx[k], bb = j + dy[k];
                    if (aa < 0 || bb < 0 || aa >= n || bb >= m)
                        continue;
                    if (num[aa][bb] == 0){
                        judge = 0;
                        break;
                    }
                }
                if(judge){
                    cnt++;
                }
            }
        }
    }
}

void dfs(int x,int y){
    st[x][y] = 1;
    for (int i = 0; i < 8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(num[a][b] !=0)
            continue;
        if(st[a][b])
            continue;
        st[a][b] = 1;
        dfs(a, b);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> p[i][j];
        }
    }
    init();
    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << num[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
    cnt_bv3_num();
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(num[i][j]==0 && !st[i][j]){
                dfs(i, j);
                bv3++;
            }
        }
    }
    cout << bv3 + cnt;
    return 0;
}