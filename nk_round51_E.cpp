#include <iostream>
#include <algorithm>
#include <cstring>
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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int N = 505;
int n;
int p[N][N];
bool st[N][N];
PII q[N * N];
int ttt;
int l, r, mid;

bool bfs(int maxn){
    memset(st, 0, sizeof st);
    if(p[1][1]>maxn || p[n][n]>maxn)
        return false;
    int hh = 0, tt = 0;
    q[0] = {1, 1};
    st[1][1] = 1;
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || b<=0 || a>n || b>n)
                continue;
            if(st[a][b])
                continue;
            if(p[a][b]>maxn)
                continue;
            if(a==n && b==n)
                return true;
            q[++tt] = {a, b};
            st[a][b] = 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> p[i][j];
            l = min(l, p[i][j]);
            r = max(r, p[i][j]);
        }
    }
    int res = r;
    while(l<=r){
        int mid = l + r >> 1;
        if(bfs(mid)){
            r = mid - 1;
            res = mid;
        }
            
        else
            l = mid + 1;
    }
    cout << res;
    return 0;
}
