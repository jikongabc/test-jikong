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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

struct Node
{
    int l, r;
    int v; // 区间 [l, r] 中的最小值
} tr[N * 4];

void pushup(int u)
{
    tr[u].v = min(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r, const vector<int> &arr)
{
    tr[u] = {l, r, inf};
    if (l == r)
    {
        tr[u].v = arr[l - 1];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid, arr);
    build(u << 1 | 1, mid + 1, r, arr);
    pushup(u);
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v; 

    int mid = tr[u].l + tr[u].r >> 1;
    int res = INT_MAX;
    if (l <= mid)
        res = min(res, query(u << 1, l, r));
    if (r > mid)
        res = min(res, query(u << 1 | 1, l, r));

    return res;
}

void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v = v;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(n);
    vector<int> index(n); 
    int idx = 1;

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        a[i].resize(m);
        index[i] = idx;
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
        idx += m;
    }

    vector<int> v;
    for (const auto &arr : a)
    {
        v.insert(v.end(), arr.begin(), arr.end());
    }

    build(1, 1, v.size(), v);
    int q;
    cin >> q;
    while (q--){
        int t;
        cin >> t;

        if (t == 1){
            int i, j, x;
            cin >> i >> j >> x;
            int pos = index[i - 1] + j - 1;
            modify(1, pos, x);
        }
        else if (t == 2){
            int i;
            cin >> i;
            int l = 1;
            int r = index[i - 1] + a[i - 1].size() - 1;
            cout << query(1, l, r) << '\n';
        }
    }

    return 0;
}
