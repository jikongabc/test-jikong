#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 205;
int n, w;
int p[N][N];
int dist[N];
bool st[N];

int prim(){
    memset(dist, inf, sizeof dist);
    memset(st, false, sizeof st);
    int res = 0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++){
            if(!st[j] && (t==-1||dist[j]<dist[t]))
                t = j;
        }
        if(i && dist[t]==inf)
            return -1;
        if(i)
            res += dist[t];
        st[t] = 1;
        for (int j = 1; j <= n;j++){
            dist[j] = min(dist[j], p[t][j]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    int cnt = 0;
    memset(p, inf, sizeof p);
    for (int i = 1; i <= w;i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(p[a][b]==inf){
            cnt++;
        }
        p[a][b] = p[b][a] = min(p[a][b], w);
        if(cnt<n-1)
            cout << -1 << endl;
        else
            cout << prim() << endl;
    }
    return 0;
}