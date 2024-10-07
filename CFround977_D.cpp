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
const int N = 1e5 + 10;

int n, m, q;
int a[N], b[N], pos[N];
map<int, int> id;

struct Node
{
    int l, r;
    int maxn;
} tr[N * 4];

void pushup(int u)
{
    tr[u].maxn = max(tr[u << 1].maxn, tr[u << 1 | 1].maxn);
}

void build(int u, int l, int r)
{
    tr[u].l = l;
    tr[u].r = r;
    if (l == r)
    {
        tr[u].maxn = pos[l];
    }
    else
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int idx, int val)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].maxn = val;
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (idx <= mid)
            modify(u << 1, idx, val);
        else
            modify(u << 1 | 1, idx, val);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l > r || tr[u].r < l)
        return 0;
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].maxn;
    return max(query(u << 1, l, r), query(u << 1 | 1, l, r));
}

void solve(){
    cin >> n >> m >> q;

        id.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            id[a[i]] = i;
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            pos[i] = id[b[i]];
        }

        build(1, 1, m);

        bool flag = true;
        for (int i = 1; i <= m; i++)
        {
            int last = query(1, 1, i - 1);
            if (pos[i] > last + 1)
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YA" : "TIDAK") << '\n';

        for (int u = 0; u < q; u++)
        {
            int li, ri;
            cin >> li >> ri;
            b[li] = ri;
            pos[li] = id[ri];
            modify(1, li, pos[li]);

            flag = true;
            for (int i = li; i <= m; i++)
            {
                int last = query(1, 1, i - 1);
                if (pos[i] > last + 1)
                {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "YA" : "TIDAK") << '\n';
        }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}