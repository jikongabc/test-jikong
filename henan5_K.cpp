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
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 4e4 + 10;
int n, m, start, end1;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int q[M];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int x)
{
    int hh = 0, tt = 0;
    memset(st, 0, sizeof st);
    q[0] = start;
    st[start] = true;
    while (hh<=tt){
        int t = q[hh++];
        if (t == end1)
            return true;
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (!st[j] && w[i] <= x){
                st[j] = true;
                q[++tt] = j;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    cin >> start >> end1;
    int l = 0, r = 1e9;
    while (l < r){
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;

    return 0;
}
