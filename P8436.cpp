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
const int N = 5e5 + 10, M = 4e6 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], dcc_cnt;
vector<int> v[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u,int f){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
        }
        else if(i!=(f^1))
            low[u] = min(low[u], dfn[j]);
    }
    if(dfn[u]==low[u]){
        int y;
        dcc_cnt++;
        do{
            y = stk[top--];
            id[y] = dcc_cnt;
            v[dcc_cnt].push_back(y);
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
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= n;i++){
        if(!dfn[i])
            tarjan(i, -1);
    }
    cout << dcc_cnt << endl;
    for (int i = 1; i <= dcc_cnt;i++){
        cout << v[i].size() << ' ';
        for(auto j:v[i])
            cout << j << ' ';
        cout << endl;
    }

        return 0;
}