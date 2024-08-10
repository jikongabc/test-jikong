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
const int N = 1e5 + 10, M = 2e6 + 10;
int n, m;
int hl[N], hr[N], e[M], ne[M], w[N], idx;
int dmin[N], dmax[N];
bool st[N];

void add(int h[],int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[],int start,int dist[],int type){
    memset(st, false, sizeof st);
    if(!type)
        memset(dist, 0x3f, sizeof dmin);
    dist[start] = w[start];
    queue<int> q;
    q.push(start);
    st[start] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(!type && dist[j]>min(dist[t],w[j]) || type && dist[j]<max(dist[t],w[j])){
                if(!type)
                    dist[j] = min(dist[t], w[j]);
                else
                    dist[j] = max(dist[t], w[j]);
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
    for (int i = 1; i <= n;i++){
        cin >> w[i];
    }
    memset(hl, -1, sizeof hl);
    memset(hr, -1, sizeof hr);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(hl, a, b), add(hr, b, a);
        if(c==2)
            add(hl, b, a), add(hr, a, b);
    }
    spfa(hl, 1, dmin, 0);
    spfa(hr, n, dmax, 1);
    int res = 0;
    for (int i = 1; i <= n;i++)
        res = max(res, dmax[i] - dmin[i]);
    cout << res << endl;
    return 0;
}
