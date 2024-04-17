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
const int N = 10010;
int n, m, k;
int dist[N];
int last[N];

struct Edge{
    int a, b, w;
} edges[N];

void bellman_ford(){
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k;i++){
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m;j++){
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    bellman_ford();
    if(dist[n]>inf/2)
        cout << "inpossible";
    else
        cout << dist[n];
    return 0;
}