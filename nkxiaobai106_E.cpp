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
#include <climits>
#include <numeric>
#include <cmath>
#define inf 0x3f3f3f3f
#define lnf LLONG_MAX
#define endl '\n'
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const double pi = acos(-1);
const int N = 500005;
const int M = 1005;
const int LOG = 20;

int n;
int h[N], e[N * 2], ne[N * 2], idx;
int depth[N], height[N];
int fa[N][LOG];
int tin[N], tout[N];
int timestamp = 0;

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, int p) {
    fa[u][0] = p;
    depth[u] = depth[p] + 1;
    tin[u] = ++timestamp;
    height[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == p) continue;
        dfs(v, u);
        height[u] = max(height[u], height[v] + 1);
    }
    tout[u] = timestamp;
}

bool is_fa(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_fa(u, v)) return u;
    if (is_fa(v, u)) return v;
    for (int k = LOG - 1; k >= 0; k--) {
        if (fa[u][k] != 0 && !is_fa(fa[u][k], v)) {
            u = fa[u][k];
        }
    }
    return fa[u][0];
}

bool cmp1(int a, int b) {
    if (height[a] != height[b]) return height[a] > height[b];
    return a < b;
}

bool cmp2(int a, int b) {
    if (depth[a] != depth[b]) return depth[a] > depth[b];
    return a < b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    depth[0] = 0;
    depth[1] = 1;
    dfs(1, 0);
    for (int k = 1; k < LOG; k++) {
        for (int u = 1; u <= n; u++) {
            fa[u][k] = fa[fa[u][k - 1]][k - 1];
        }
    }
    int max_depth = 0;
    for (int i = 1; i <= n; i++){
		max_depth = max(max_depth, depth[i]);    
    }
    vector<int> points(n);
    for (int i = 1; i <= n; i++) points[i-1] = i;
    sort(points.begin(), points.end(), cmp1);
    int sz = (int)points.size() < M ? (int)points.size() : M;
    vector<int> v1(points.begin(), points.begin() + sz);
    sort(points.begin(), points.end(), cmp2);
    sz = (int)points.size() < M ? (int)points.size() : M;
    vector<int> v2(points.begin(), points.begin() + sz);
    int res = max_depth;
    for (auto u : v1) {
        if (u == 1) continue;
        for (auto v : v2) {
            if (v == 1 || v == u) continue;
            int p = lca(u, v);
            if (p != u && p != v) {
                int res1 = depth[v] + height[u] - 1;
                int res2 = depth[u] + height[v] - 1;
                res = max(res, max(res1, res2));
            }
        }
    }
    cout << res << "\n";
    return 0;
}
