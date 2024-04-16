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
const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(){
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n;i++){
        int temp = -1;
        for (int j = 1; j <= n;j++){
            if(!st[j] &&(temp==-1|| dist[temp]>dist[j] ))
                temp = j;
        }
        st[temp] = 1;
        for (int j = 1; j <= n;j++){
            dist[j] = min(dist[j], dist[temp] + g[temp][j]);
        }
    }
    if(dist[n]==inf)
        return -1;
    else
        return dist[n];
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
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra();
    return 0;
}