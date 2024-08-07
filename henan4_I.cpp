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
const int N = 6e5 + 10;
int n, x, y;
int e[N], ne[N], h[N], idx;
int sz[N];
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = 1;
    sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j])
            continue;
        sz[j] = dfs(j);
        sz[u] += sz[j];
    }
    return sz[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    memset(h, -1, sizeof h);
    bool pd = false;
    for (int i = 0; i < n - 1;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        if(a==x && b==y || a==y && b==x)
            pd = true;
    }
    dfs(x);
    int minn = min(sz[x], sz[y]);
    memset(sz, 0, sizeof sz);
    memset(st, false, sizeof st);
    dfs(y);
    int minnn = min(sz[x], sz[y]);
    // sz[x]*sz[y]*x->y路线数量
    cout << minnn * minn;
    return 0;
}
