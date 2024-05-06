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
const int N = 1005, M = N * N;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n;
int p[N][N];
PII q[M];
PII pre[N][N];

void bfs(){
    memset(pre, -1, sizeof pre);
    int hh = 0, tt = 0;
    q[0] = {n-1, n-1};
    while(hh<=tt){
        auto t = q[hh++];
        for (int i = 0; i < 4;i++){
            int a = t.first + dx[i], b = t.second + dy[i];
            if(a<0 || b<0 || a>=n || b>=n)
                continue;
            if(pre[a][b].first!=-1)
                continue;
            if(p[a][b])
                continue;
            q[++tt] = {a, b};
            pre[a][b] = t;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> p[i][j];
        }
    }
    bfs();
    PII end(0, 0);
    while (true){
        cout << end.first << ' ' << end.second << endl;
        if(end.first==n-1 && end.second==n-1)
            break;
        end = pre[end.first][end.second];
    }
    return 0;
}