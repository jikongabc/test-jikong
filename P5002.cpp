#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e4 + 10, M = 1e5 + 10;
int n, m;
int root;
int h[N], e[M], ne[M], idx;
int sz[N];
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u){
    sz[u] = 1;
    st[u] = 1;
    for (int i = h[u]; ~i;i=ne[i]){
        int j = e[i];
        if(st[j])
            continue;
        sz[j] = dfs(j);
        sz[u] += sz[j];
    }
    return sz[u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> root >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n;i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(root);
    while(m--){
        int x;
        cin >> x;
        LL res = 0;
        for (int i = h[x]; ~i;i=ne[i]){
            int j = e[i];
            if(sz[j]<sz[x])
                res += sz[j] * (sz[x] - sz[j]);
        }
        res += sz[x];
        cout << res << endl;
    }
    return 0;
}
