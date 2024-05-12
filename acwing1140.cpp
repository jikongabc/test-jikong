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
const int N = 105;
int n;
int g[N][N];
int dist[N];
bool st[N];

int prim(){
    memset(dist, inf, sizeof dist);
    int res = 0;
    dist[1] = 0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++){
            if(!st[j]&&(t==-1|| dist[t]>dist[j]))
                t = j;
        }
        res += dist[t];
        st[t] = 1;
        for (int j = 1; j <= n;j++){
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> g[i][j];
        }
    }
    cout << prim();
    return 0;
}