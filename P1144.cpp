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
typedef pair<int, PII> PIII;
const int N = 4e6 + 10;
const int mod = 100003;

int n, m;
int e[N], ne[N], h[N], idx;
int dist[N];
bool st[N];
int ans[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist, inf, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dist[1] = 0;
    ans[1] = 1;
    while(q.size()){
        auto t = q.top();
        q.pop();
        int ver = t.second;
        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+1){
                dist[j] = dist[ver] + 1;
                ans[j] = ans[ver];
                ans[j] %= mod;
                q.push({dist[j], j});
            }
            else if(dist[j]==dist[ver]+1){
                ans[j] += ans[ver];
                ans[j] %= mod;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dijkstra();
    for (int i = 1; i <= n;i++){
        cout << ans[i] % mod << endl;
    }
    return 0;
}

