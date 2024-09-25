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
const int N = 1010, M = 510;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
bool cut[N];
int root, cnt;
vector<int> dcc[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    if(u==root && h[u]==-1){
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
    int cnt = 0;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j]){
                cnt++;
                if (u != root || cnt > 1)
                    cut[u] = true;
                dcc_cnt++;
                int y;
                do
                {
                    y = stk[top--];
                    dcc[dcc_cnt].push_back(y);
                } while (y != j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else
            low[u] = min(low[u], dfn[j]);
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    while(cin>>m,m){
        for (int i = 1; i <= dcc_cnt;i++)
            dcc[i].clear();
        n = idx = timestamp = dcc_cnt = top = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(cut, 0, sizeof cut);
        while(m--){
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
            n = max({n, a, b});
        }
        for (root = 1; root <= n;root++){
            if(!dfn[root])
                tarjan(root);
        }
        ULL res = 0, num = 1;
        for (int i = 1; i <= dcc_cnt;i++){
            int cnt = 0;
            for (int j = 0; j < dcc[i].size();j++){
                if(cut[dcc[i][j]])
                    cnt++;
            }
            if(!cnt){
                if(dcc[i].size()>1){
                    res += 2;
                    num *= dcc[i].size() * (dcc[i].size() - 1) / 2;
                }
                else
                    res++;
            }
            else if(cnt==1){
                res++;
                num *= dcc[i].size() - 1;
            }
        }
        printf("Case %d: %llu %llu\n", T++, res, num);
    }
    return 0;
}