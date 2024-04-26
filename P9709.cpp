// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <cmath>
// #define inf 0x3f3f3f3f
// using namespace std;
// using LL = long long;
// using ULL = unsigned long long;
// typedef pair<int, int> PII;
// const int N = 2005, M = 4e6 + 5;
// int dx[] = {-1, 1, 2, -2, -1, 1, 2, -2};
// int dy[] = {2, 2, 1, 1, -2, -2, -1, -1};
// int n, m;
// int cnt;
// int fa[N];
// int x[N], y[N];
// int dist[N][N];
// int st[N][N];

// struct Edges
// {
//     int a, b, w;
//     bool operator<(const Edges &ll) const
//     {
//         return w < ll.w;
//     }
// } edges[M];

// struct node
// {
//     int x, y;
//     bool operator<(const node &rr) const
//     {
//         if (x != rr.x)
//             return x < rr.x;
//         return y < rr.y;
//     }
// } a[N];

// struct step
// {
//     int x, y, len;
// };

// // bool cmp(Edges a, Edges b)
// // {
// //     return a.w < b.w;
// // }

// int find(int x)
// {
//     if (fa[x] != x)
//         fa[x] = find(fa[x]);
//     return fa[x];
// }

// void bfs(int x1, int y1,int u)
// {
//     int q_x[100000], q_y[100000], q_step[10000];
//     int hh = 0, tt = -1;
//     // queue<PII> q;
//     // q.push({x1, y1});
//     q_x[++tt] = x1, q_y[++tt] = y1, q_step[++tt] = 0;
//     dist[x1][y1] = 0;
//     st[x1][y1] = 0;
//     while (hh<=tt)
//     {
//         // auto t = q.front();
//         // q.pop();
//         int xx = q_x[hh++], yy = q_y[hh++];
//         for (int i = 0; i < 8; i++)
//         {
//             int a = xx + dx[i], b = yy + dy[i];
//             if (a <= 0 || b <= 0 || a > m || b > m)
//                 continue;
//             if (dist[a][b] >= 0)
//                 continue;
//             dist[a][b] = dist[xx][yy] + 1;
//             if(st[a][b])
//                 edges[cnt++] = {u, st[a][b], dist[a][b]};
//             // q.push({a, b});
//             q_x[++tt] = a, q_y[++tt] = b;
//         }
//     }
//     return;
// }

// int kruskal()
// {
//     int res = 0;
//     sort(edges, edges + cnt);
//     // for (int i = 1; i <= n; i++)
//     //     fa[i] = i;
//     for (int i = 0; i < cnt; i++)
//     {
//         int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//         a = find(a), b = find(b);
//         if (a != b)
//         {
//             fa[a] = b;
//             res += w;
//         }
//     }
//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i].x >> a[i].y;
//     }
//     sort(a + 1, a + n + 1);
//     for (int i = 1; i <= n; i++)
//         st[a[i].x][a[i].y] = fa[i] = i;
//     for (int i = 1; i <= n; i++)
//     {
//         memset(dist, -1, sizeof dist);
//         // while (!q.empty())
//         //     q.pop();
//         bfs(a[i].x, a[i].y, i);
//         // for (int j = i + 1; j <= n; j++)
//         // {
//         //     edges[cnt++] = {i, j, dist[x[j]][y[j]]};
//         // }
//         }
//     // for (int i = 1; i <= m;i++){
//     //     for (int j = 1; j <= m;j++){
//     //         cout << dist[i][j] << ' ';
//     //     }
//     //     cout << endl;
//     // }
//     // for (int i = 0; i < cnt;i++){
//     //     cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w << endl;
//     // }
//     cout << kruskal()+n-1;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5, MR = 9e6 + 5, MN = 2e2 + 5;
int n, m, cnt, ans, mp[MN][MN], f[MN][MN], fa[MAXN];
struct edge
{
    int x, y, len;
    bool operator<(const edge &ll) const
    {
        return len < ll.len;
    }
} e[MR];
struct node
{
    int x, y;
    bool operator<(const node &rr) const
    {
        if (x != rr.x)
            return x < rr.x;
        return y < rr.y;
    }
} a[MAXN];
struct step
{
    int x, y, len;
};
int dx[] = {-1, 1, 2, -2, -1, 1, 2, -2};
int dy[] = {2, 2, 1, 1, -2, -2, -1, -1};
void bfs(int sx, int sy)
{
    queue<step> q;
    q.push({sx, sy, 0});
    memset(f, 0, sizeof(f));
    f[sx][sy] = 1;
    while (!q.empty())
    {
        int tx = q.front().x, ty = q.front().y, tl = q.front().len;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int px = tx + dx[i], py = ty + dy[i];
            if (f[px][py] || px <= 0 || py <= 0 || px > m || py > m)
                continue;
            if (mp[px][py])
                e[++cnt] = {mp[sx][sy], mp[px][py], tl + 1};
            f[px][py] = 1;
            q.push({px, py, tl + 1});
        }
        //        printf("%d %d %d\n", tx, ty, tl);
    }
}
int find(int u)
{
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        mp[a[i].x][a[i].y] = fa[i] = i;
    for (int i = 1; i <= n; i++)
        bfs(a[i].x, a[i].y);
    sort(e + 1, e + cnt + 1);
    for (int i = 1; i <= cnt; i++)
    {
        int tx = e[i].x, ty = e[i].y, tl = e[i].len;
        if (find(tx) != find(ty))
        {
            fa[find(tx)] = find(ty);
            ans += tl;
        }
    }
    printf("%d", ans + n - 1);
    return 0;
}