#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<double, int> PDI;
const int N = 1005, M = N * N + 10;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int n, m;
string p[N];
bool st[N][N];
PII q[M];
void bfs(int x,int y){
    int hh = 0, tt = 0;
    q[0] = {x, y};
    st[x][y] = 1;
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 8;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=m)
                continue;
            if (p[a][b] != 'W')
                continue;
            if (st[a][b])
                continue;
            q[++tt] = {a, b};
            st[a][b] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n;i++)
        cin >> p[i];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(p[i][j]=='W' && !st[i][j]){
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
