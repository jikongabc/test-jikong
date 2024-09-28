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
const int N = 52, M = N * N;
int n = 52; // A~Z --> 0~25  a~z--> 26 ~ 51
int m;
int d[N];
int ans[M], cnt;
int g[N][N];
int fa[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void dfs(int u)
{
    for (int i = 0; i < n; i++)
    {
        if (g[u][i])
        {
            g[u][i] = g[i][u] = 0;
            dfs(i);
        }
    }
    ans[++cnt] = u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        char ch1, ch2;
        string s;
        cin >> s;
        ch1 = s[0], ch2 = s[1];
        int a, b;
        if (ch1 >= 'a' && ch1 <= 'z')
            a = ch1 - 'a' + 26;
        else
            a = ch1 - 'A';
        if (ch2 >= 'a' && ch2 <= 'z')
            b = ch2 - 'a' + 26;
        else
            b = ch2 - 'A';
        d[a]++, d[b]++;
        g[a][b] = g[b][a] = 1;
        int pa = find(a), pb = find(b);
        fa[pa] = pb;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (fa[i] == i && d[i])
            cnt2++;
    }
    if (cnt2 != 1)
    {
        cout << "No Solution";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] & 1)
        {
            cnt1++;
            if (start == 0)
                start = i;
        }
    }
    if (cnt1 && cnt1 != 2)
    {
        cout << "No Solution";
        return 0;
    }
    if (start == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (d[i])
            {
                start = i;
                break;
            }
        }
    }
    dfs(start);
    for (int i = cnt; i; i--)
    {
        if (ans[i] <= 25)
            cout << (char)('A' + ans[i]);
        else
            cout << (char)('a' + ans[i] - 26);
    }
    return 0;
}