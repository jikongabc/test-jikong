#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 105, M = 5005;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m, k;
int x[M], y[M];
int p[N][N];
bool st[N][N];
int dist[N][N];
int cnt[1000005];
queue<PII> q;
int x1, y1;

struct node{
    int x, y, id, num;
}d[M];

bool cmp(node a,node b){
    return a.num < b.num;
}

void bfs(){
    q.push({x1, y1});
    st[x1][y1] = 1;
    memset(dist, -1, sizeof dist);
    dist[x1][y1] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<=0 || b<=0 || a>n || b>m)
                continue;
            if(!p[a][b])
                continue;
            if(dist[a][b]>=0)
                continue;
            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> p[i][j];
            if(p[i][j]==2){
                x1 = i, y1 = j;
            }
        }
    }
    bfs();
    cin >> k;
    for (int i = 1; i <= k;i++){
        int b, a;
        cin >> b >> a;
        d[i] = {a, b, i, dist[a][b]};
        if(dist[a][b]!=-1)
            cnt[dist[a][b]]++;
    }
    sort(d + 1, d + k + 1, cmp);
    for (int i = 1; i <= k;i++){
        if(d[i].num!=-1 && cnt[d[i].num]==1){
            cout << d[i].id << ' ' << d[i].num;
            return 0;
        }
    }
    cout << "No winner";
    return 0;
}