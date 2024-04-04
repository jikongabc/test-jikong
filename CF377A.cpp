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
const int N = 505;
int n, m, k;
char ch[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int cnt, cnt_;

void dfs(int x,int y){
    if(cnt==cnt_-k)
        return;
    cnt++;
    ch[x][y] = '.';
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(ch[a][b]!='X')
            continue;
        dfs(a, b);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> ch[i][j];
            if(ch[i][j]=='.'){
                ch[i][j] = 'X';
                cnt_++;
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(ch[i][j]=='X'){
                dfs(i, j);
                for (int x = 0; x < n;x++){
                    cout << ch[x] << endl;
                }
                return 0;
            }
        }
    }
    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < m;j++){
    //         cout << ch[i][j];
    //     }
    //     cout << endl;
    // }
        return 0;
}