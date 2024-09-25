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
const int dx[] = {-1, -1, 1, 1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int n, m, t;
int g[N][N];
PII match[N][N];
bool st[N][N];
int res;

bool dfs(int x,int y){
    for (int i = 0; i < 8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<=0 || b<=0 || a>n || b>m)
            continue;
        if(st[a][b] || g[a][b])
            continue;
        st[a][b] = 1;
        PII t = match[a][b];
        if(!t.first || dfs(t.first,t.second))
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for(int i=0;i<t;i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(g[i][j] || (i+j)%2)
                continue;
            memset(st, false, sizeof st);
            if(dfs(i,j))
                res++;
        }
    }
    cout << n * m - t - res;
    return 0;
}