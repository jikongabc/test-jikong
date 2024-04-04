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
const int N = 105;
int n, m;
int ans;
char ch[N][N];
bool st[N][N];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};

void dfs(int x,int y){
    for (int i = 0; i < 8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(ch[a][b]!='@')
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
    while(cin >> n >> m){
        memset(st, 0, sizeof st);
        ans = 0;
        if(!m && !n)
            break;
        for (int i = 0; i < n; i++)
            cin >> ch[i];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (ch[i][j] == '@' && !st[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
