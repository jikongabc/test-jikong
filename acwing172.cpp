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
#define inf 0x3f3f3f3f
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 40010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16];
int q[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root){
    memset(depth, inf, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    int hh = 0, tt = 0;
    q[0] = root;
    while(hh<=tt){
        int t = q[hh++];
        for (int i = h[t]; ~i;i=ne[i]){
            int j = e[i];
            if(depth[j]>depth[t]+1){
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                for (int k = 1; k <= 15;k++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a, b);
    for (int k = 15; k >= 0;k--){
        if(depth[fa[a][k]]>=depth[b])
            a = fa[a][k];
    }
    if(a==b)
        return a;
    for (int k = 15; k >= 0;k--){
        if(fa[a][k]!=fa[b][k])
            a = fa[a][k], b = fa[b][k];    
    }
    return fa[a][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int root = 0;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        if(b==-1)
            root = a;
        else
            add(a, b), add(b, a);
    }
    bfs(root);
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        if(p==a)
            cout << 1 << endl;
        else if(p==b)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}