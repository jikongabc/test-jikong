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
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int N = 15;
int n, m, x, y;
int p[N][N];
bool st[N][N];
int ans;

void dfs(int x,int y,int cnt){
    if(cnt==n*m){
        ans++;
        return;
    }
    st[x][y] = 1;
    for (int i = 0; i < 8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0 || b<0 || a>=n || b>=m)
            continue;
        if(st[a][b])
            continue;
        dfs(a, b, cnt + 1);
    }
    st[x][y] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m >> x >> y;
        ans = 0;
        dfs(x, y, 1);
        cout << ans;
    }
    return 0;
}