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
const int N = 5e5 + 10, M = 1e6 + 10;
int n, m;
int root;
int depth[N];
int h[N], e[M], ne[M], idx;
int fa[N][21];
int q[M];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[root] = 1;
    int hh = 0, tt = 0;
    q[0] = root;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j]=depth[t]+1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 20;k++){
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int k = 20; k >= 0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b)
        return a;
    for (int k = 20; k >= 0;k--){
        if (fa[a][k]!=fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> root;
    memset(h, -1, sizeof h);
    n--;
    while(n--){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bfs();
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
