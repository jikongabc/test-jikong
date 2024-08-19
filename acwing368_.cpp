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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 6e5 + 10;
int n, m;
int h[N], hs[N], e[M], ne[M], w[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool st[N];
int id[N], cnt, sz[N];
int dist[N];

void add(int h[],int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, st[u] = 1;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(st[j])
            low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        int y;
        do{
            y = stk[top--];
            st[y] = 0;
            id[y] = cnt;
            sz[cnt]++;
        } while (y != u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++){
        add(h, 0, i, 1);
    }
    while(m--){
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            add(h, b, a, 0), add(h, a, b, 0);
        else if (t == 2)
            add(h, a, b, 1);
        else if (t == 3)
            add(h, b, a, 0);
        else if (t == 4)
            add(h, b, a, 1);
        else
            add(h, a, b, 0);
    }
    tarjan(0);
    memset(hs, -1, sizeof h);
    bool flag = true;
    for (int i = 0; i <= n;i++){
        for (int j = h[i]; ~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a==b && w[j]){
                flag = false;
                break;
            }
            if(a!=b)
                add(hs, a, b, w[j]);
        }
        if(!flag)
            break;
    }
    if(!flag)
        cout << -1 << endl;
    else{
        for (int i = cnt; i;i--){
            for (int j = hs[i]; ~j;j=ne[j]){
                int k = e[j];
                dist[k] = max(dist[k], dist[i] + w[j]);
            }
        }
        LL res = 0;
        for (int i = 1; i <= cnt;i++)
            res += (LL)dist[i] * sz[i];
        cout << res << endl;
    }
    return 0;
}
