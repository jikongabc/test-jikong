#include <bits/stdc++.h>

using namespace std;

const int N = 50010, M = 150010;

int n;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    st[0] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[50001];
}

int main()
{
    cin >> n;

    memset(h, -1, sizeof h);

    for (int i = 1; i <= 50001; i++)
    {
        add(i - 1, i, 0);  // s[i] >= s[i-1]
        add(i, i - 1, -1); // s[i-1] >= s[i] - 1
    }

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++;         // 把 0 的位置腾出来
        add(a - 1, b, c); // s[b] >= s[a-1] + c
    }

    cout << spfa() << endl;

    return 0;
}