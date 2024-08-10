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
const int N = 1e5 + 10, M = 4e5 + 10;
const int mod = 100003;
int n, m;
int e[M], ne[M], h[N], idx;
int q[M];
int dist[N];
int cnt[N];
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(dist, 0x3f, sizeof dist);
    int hh = 0, tt = 0;
    q[0] = 1;
    cnt[1] = 1;
    dist[1] = 0;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+1){
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q[++tt] = j;
            }
            else if(dist[j]==dist[t]+1){
                cnt[j] = (cnt[j] + cnt[t]) % mod;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs();
    for (int i = 1; i <= n;i++){
        cout << cnt[i] << endl;
    }
        return 0;
}
