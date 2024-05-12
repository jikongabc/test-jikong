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
const int N = 1010, M = 2*N * N;
int sum;
int n, m, k;
int ids[N][N];
int fa[M];

struct Edge
{
    int a, b, w;
} edges[M];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void get_edges(){
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, dw[] = {1, 2, 1, 2};
    for (int z = 0; z < 2;z++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                for (int u = 0; u < 4;u++){
                    if(u%2==z){
                        int x = i + dx[u], y = j + dy[u], w = dw[u];
                        if(x && x<=n && y && y<=m){
                            int a = ids[i][j], b = ids[x][y];
                            if(a<b)
                                edges[k++] = {a, b, w};
                        }
                    } 
                }
            }
        }
    }
}

int kruskal()
{
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            fa[a] = b;
            res += w;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int t = 1;
    for (int i = 1; i <= n * m; i++)
        fa[i] = i;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            ids[i][j] = t++;
        }
    }
    int x1, y1, x2, y2;
    while(cin>>x1>>y1>>x2>>y2){
        int a = ids[x1][y1], b = ids[x2][y2];
        a = find(a), b = find(b);
        fa[a] = b;
    }
    get_edges();
    cout << kruskal();
    return 0;
}