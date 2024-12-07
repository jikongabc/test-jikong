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
#include <bitset>
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 2e5 + 10;
int n, k, a, b, x, y;
int dist1[N], dist2[N];
int q[N];

void bfs(int start, int dist[]){
    fill(dist, dist + n, inf);
    dist[start] = 0;
    int hh = 0, tt = 0;
    q[tt++] = start;
    while(hh <= tt){
        int t = q[hh++];
        int v1 = (t + x) % n;
        int v2 = (t - y + n) % n;
        if(dist[v1] > dist[t] + 1){
            dist[v1] = dist[t] + 1;
            q[tt++] = v1;
        } 
        if(dist[v2] > dist[t] + 1){
            dist[v2] = dist[t] + 1;
            q[tt++] = v2;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    cin >> n >> k >> a >> b >> x >> y;
    a--, b--;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    bfs(a, dist1);
    int d0 = dist1[b];
    bfs((a + n / 2) % n, dist2);
    int d1 = dist2[b];
    int res = inf;
    if(d0 != inf) res = min(res, d0);
    if(k >= 1 && d1 != inf) res = min(res, d1 + 1);
    cout << ((res == inf) ? -1 : res) << "\n"; 
    return 0;
}
