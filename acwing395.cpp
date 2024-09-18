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
const int N = 5e3 + 10, M = 2e4 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool is_bridge[M];
int id[N], dcc_cnt, d[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if(dfn[u]<low[j]){
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        }
        else if (i != (fa^1))
            low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]){
        int y;
        dcc_cnt++;
        do{
            y = stk[top--];
            id[y] = dcc_cnt;
        } while (y != u);
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
    tarjan(1, -1);
    for (int i = 0; i < idx;i++){
        if(is_bridge[i])
            d[id[e[i]]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= dcc_cnt;i++){
        if(d[i]==1)
            cnt++;
    }
    cout << (cnt + 1) / 2;
    return 0;
}