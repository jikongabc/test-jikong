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
const int N = 2e4 + 10;
int n;
int h[N], e[N], ne[N], w[N], idx;
int res;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u,int fa){
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j==fa)
            continue;
        int d = dfs(j, u) + w[i];
        if(d>d1)
            d2 = d1, d1 = d;
        else if(d>d2)
            d2 = d;
    }
    res = max(res, d1 + d2);
    return d1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << res;
    return 0;
}