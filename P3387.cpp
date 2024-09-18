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
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], rh[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int w[N], rw[N];
int dp[N];

void add(int h[],int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[j], low[u]);
        }
        else if(in_stk[j])
            low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u]==low[u]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            rw[scc_cnt] += w[y];
        } while (y != u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> w[i];
    }
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(h, a, b);
    }
    for (int i = 1; i <= n;i++)
        if(!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n;i++){
        for (int j = h[i]; ~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a!=b)
                add(rh, a, b);
        }
    }
    for (int i = scc_cnt; i > 0;i--){
        if(!dp[i])
            dp[i] = rw[i];
        for (int j = rh[i]; ~j;j=ne[j]){
            int k = e[j];
            dp[k] = max(dp[k], dp[i] + rw[k]);
        }
    }
    int res = 0;
    for (int i = 1; i <= scc_cnt;i++)
        res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}