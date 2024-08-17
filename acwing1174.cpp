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
const int N = 1e4 + 10, M = 5e4 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool st[N];
int id[N], cnt, sz[N];
int dout[N];

void add(int a,int b){
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
        ++cnt;
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
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n;i++){
        if(!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n;i++){
        for (int j = h[i]; ~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a!=b)
                dout[a]++;
        }
    }
    int zeros = 0, sum = 0;
    for (int i = 1; i <= cnt;i++){
        if(!dout[i]){
            zeros++;
            sum += sz[i];
        }
    }
    cout << (zeros > 1 ? 0 : sum) << endl;
    return 0;
}
