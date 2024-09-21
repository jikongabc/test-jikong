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
const int N = 2e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root;
vector<int> res;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    int cnt = 0;
    dfn[u] = low[u] = ++timestamp;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j])
                cnt++;
        }
        else
            low[u] = min(low[u], dfn[j]);
    }
    if (u != root)
        cnt++;
    if(cnt>1)
        res.push_back(u);
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
    for (root = 1; root <= n;root++){
        if(!dfn[root])
            tarjan(root);
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto i:res)
        cout << i << ' ';
    return 0;
}