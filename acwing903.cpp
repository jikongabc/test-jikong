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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 110;
int n, m;
int d[N][N], lv[N];
int dist[N];
bool st[N];

int dijkstra(int l,int r){
    memset(dist, inf, sizeof dist);
    memset(st, false, sizeof st);
    dist[0] = 0;
    for (int i = 0; i < n + 1;i++){
        int t = -1;
        for (int j = 0; j <= n;j++){
            if(!st[j] &&( t==-1||dist[t]>dist[j]))
                t = j;
        }
        st[t] = 1;
        for (int j = 1; j <= n;j++){
            if(lv[j]>=l && lv[j]<=r)
                dist[j] = min(dist[j], dist[t] + d[t][j]);
        }
    }
    return dist[1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = inf;
        }
    }
        
    for (int i = 1; i <= n; i++)
    {
        int price, cnt;
        cin >> price >> lv[i] >> cnt;
        d[0][i] = min(price, d[0][i]);
        while (cnt--)
        {
            int id, cost;
            cin >> id >> cost;
            d[id][i] = min(d[id][i],cost);
        }
    }
    int ans = inf;
    for (int i = lv[1] - m; i <= lv[1]; i++)
        ans = min(ans, dijkstra(i, i + m));
    cout << ans;
    return 0;
}