#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 300010;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int q[N], cnt[N];
long long d[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa()
{
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++)
    {
        q[tt++] = i;
        st[i] = true;
        d[i] = 1;
    }

    while (hh < tt)
    {
        int t = q[hh++];
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (d[j] < d[t] + w[i])
            {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                    q[tt++] = j, st[j] = true;
            }
        }
    }

    return false;
}
intmain()
{
    // 最小值最长路,i->j,dj>=di+c

    memset(h, -1, sizeof h);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        if (type == 1)
            add(a, b, 0), add(b, a, 0); // A=B,A>=B,B>=A
        if (type == 2)
            add(a, b, 1); // A<B,B-1>=A
        if (type == 3)
            add(b, a, 0); // A>=B,B->A
        if (type == 4)
            add(b, a, 1); // A>B,A>=B+1,B->A
        if (type == 5)
            add(a, b, 0); // A<=B,B>=A,A->B
    }

    if (spfa())
        puts("-1");
    else
    {
        long long res = 0;
        for (int i = 1; i <= n; i++)
            res += d[i];
        cout << res;
    }

    return 0;
}