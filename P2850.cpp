#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 505, M = 1e6 + 10;
int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa(){
    queue<int> q;
    memset(dist, inf, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, false, sizeof st);
    dist[1] = 0;
    for (int i = 1; i <= n;i++){
        q.push(i);
        st[i] = 1;
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n)
                    return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w), add(b, a, w);
    }
    while(k--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, -w);
    }
    if(spfa())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}