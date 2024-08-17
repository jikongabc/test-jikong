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
#include <unordered_set>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2e6 + 10;
int n, m, mod;
int h[N], hs[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool st[N];
int id[N], cnt, sz[N];
int f[N], g[N];

void add(int h[],int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
    cin >> n >> m >> mod;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        add(h, a, b);
    }
    for (int i = 1; i <= n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    memset(hs, -1, sizeof hs);
    unordered_set<LL> S;
    for (int i = 1; i <= n;i++){
        for (int j = h[i]; ~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            LL hash = a * 1000000ll + b;
            if(a!=b && !S.count(hash)){
                add(hs, a, b);
                S.insert(hash);
            }
        }
    }
    for (int i = cnt; i;i--){
        if(!f[i]){
            f[i] = sz[i];
            g[i] = 1;
        }
        for (int j = hs[i]; ~j; j = ne[j]){
            int k = e[j];
            if (f[k] < f[i] + sz[k]){
                f[k] = f[i] + sz[k];
                g[k] = g[i];
            }
            else if (f[k] == f[i] + sz[k])
                g[k] = (g[k] + g[i]) % mod;
        }
    }
    int maxn = 0, sum = 0;
    for (int i = 1; i <= cnt;i++){
        if(f[i]>maxn){
            maxn = f[i];
            sum = g[i];
        }
        else if(f[i]==maxn)
            sum = (sum + g[i]) % mod;
    }
    cout << maxn << endl;
    cout << sum << endl;
    return 0;
}
