#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim(){
    memset(dist, inf, sizeof dist);
    int res = 0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++)
            if(!st[j] &&(t==-1|| dist[t]>dist[j]))
                t = j;
        if(i && dist[t]==inf)
            return inf;
        if(i)
            res += dist[t];
        st[t] = 1;
        for (int j = 1; j <= n;j++)
            dist[j] = min(dist[j], g[t][j]);
        
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(g, inf, sizeof g);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if(t==inf)
        cout << "impossible";
    else
        cout << t;
    return 0;
}
