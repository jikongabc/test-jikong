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
typedef pair<double, int> PDI;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
const int N = 25;
int n, m;
int x1, y1;
char p[N][N];
bool st[N][N];
int res;

int dfs(int x,int y){
    res++;
    st[x][y] = 1;
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>= n|| b>=m)
            continue;
        if(p[a][b]=='#')
            continue;
        if(st[a][b])
            continue;
        st[a][b] = 1;
        dfs(a, b);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> m >> n){
        if(!m && !n)
            break;
        memset(st, false, sizeof st);
        res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m;j++){
                cin >> p[i][j];
                if(p[i][j]=='@')
                    x1 = i, y1 = j;
            }
        }
        cout << dfs(x1, y1) << endl;
    }

        return 0;
}
