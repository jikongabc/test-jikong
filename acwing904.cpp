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
const int N = 510, M = 5210;
int n, m, k;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];
int cnt[N];
int q[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool  spfa(){
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, false, sizeof st);
    int hh = 0, tt = 0;
    for (int i = 1; i <= n;i++){
        q[tt++] = i;
        st[i] = 1;
    }
    while(hh!=tt){
        int t = q[hh++];
        if(hh==N)
            hh = 0;
        st[t] = 0;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                {
                    q[tt++] = j;
                    if(tt==N)
                        tt = 0;
                    st[j] = 1;
                }
            }
            
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m >> k;
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
    return 0;
}