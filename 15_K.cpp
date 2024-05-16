#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;
int n, m, q, p;
int fa[N];
int cnt[N];
LL res[N];
int temp;
struct Edge
{
    int a, b, w;
} edges[N];

struct node
{
    int z, id;
} ask[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

bool cmp1(node a, node b)
{
    return a.z > b.z;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(cnt, 0, sizeof cnt);
        memset(res, 0, sizeof res);
        cin >> n >> m >> q;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            edges[i] = {a, b, w};
        }
        sort(edges, edges + m, cmp);
        for (int i = 0; i < q; i++)
        {
            cin >> ask[i].z;
            ask[i].id = i;
        }
        sort(ask, ask + q, cmp1);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            cnt[i] = 1;
        }
        LL ans = 0;
        for (int i = 0; i < q; i++)
        {
            for (int j = temp; j < m && edges[j].w >= ask[i].z; j++)
            {
                int a = edges[j].a, b = edges[j].b, w = edges[j].w;
                a = find(a), b = find(b);
                if (a != b)
                {
                    fa[a] = b;
                    ans += cnt[a] * cnt[b];
                    cnt[b] += cnt[a];
                }

                temp = j + 1;
            }

            res[ask[i].id] = ans;
        }
        for (int i = 0; i < q; i++)
        {
            cout << res[i] << endl;
        }
    }

    return 0;
}