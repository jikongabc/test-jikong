#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 305;
int g[N][N];
int dist[N];
bool st[N];
int price[N];
int minn = inf;
int n;

int prim(){
    memset(dist, inf, sizeof dist);
    dist[0] = 0;
    int res = 0;
    for (int i = 0; i < n+1;i++){
        int t = -1;
        for (int j = 0; j <= n;j++){
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t = j;
        }
        res += dist[t];
        st[t] = 1;
        for (int j = 0; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> g[0][i];
        g[i][0] = g[0][i];
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> g[i][j];
        }
    }
    cout << prim();
    return 0;
}