#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10;
int n, m;
int fa[N];
int ans;
int temp;
bool vis[N];

void init(int n){
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x){
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

// void merge(int i, int j){
//     fa[find(i)] = find(j);
// }

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    scanf("%d%d", &n, &m);
    // init(n);
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
        for (int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            int aa = find(a), bb = find(b);
            if (aa == bb){
                vis[aa] = 1;
            }
            else{
            // merge(a, b);
            fa[aa] = bb;
            if (vis[aa] || vis[bb])
                vis[bb] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        if (find(i) == i && !vis[i])
            ans++;
    }
    printf("%d", ans);
    return 0;
}