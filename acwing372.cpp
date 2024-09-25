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
#include <bitset>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 105;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m;
bool g[N][N];
PII match[N][N];
int res;
bool st[N][N];

bool dfs(int x,int y){
    for (int i = 0; i < 4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<=0 || b<=0 || a>n || b>n)
            continue;
        if(st[a][b])
            continue;
        st[a][b] = 1;
        if(!match[a][b].first || dfs(match[a][b].first,match[a][b].second)){
            match[a][b] = {x, y};
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(g[i][j] || (i+j)%2 )
                continue;
            memset(st, false, sizeof st);
            if(dfs(i,j))
                res++;
        }
    }
    cout << res;
    return 0;
}