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
const int N = 4e5 + 10;
int n, m, k;
int cnt;
int res;
int ask[N];
int fa[N];
int ans[N];
int h[N], e[N], ne[N], idx;
bool st[N];

struct Edge{
    int a, b;
} edges[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n;i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
        edges[cnt++] = {a, b};
        edges[cnt++] = {b, a};
    }
    cin >> k;
    res = n - k;
    for (int i = 0; i < k;i++){
        cin >> ask[i];
        st[ask[i]] = true;
    }
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b;
        int pa = find(a), pb = find(b);
        if (!st[a] && !st[b]){
            if(pa!=pb){
                fa[pa] = pb;
                res--;
            }
        }
    }
    // cout << res << endl;
    ans[k] = res;
    for (int i = k - 1; i >= 0;i--){
        int t = ask[i];
        st[ask[i]] = false;
        res++;
        for (int j = h[t]; ~j;j=ne[j]){
            int k = e[j];
            int pt = find(t), pk = find(k);
            if(!st[k] && pt!=pk){
                fa[pt] = pk;
                res--;
            }
        }
        ans[i] = res;
    }
    for (int i = 0; i <= k;i++)
        cout << ans[i] << endl;
    return 0;
}