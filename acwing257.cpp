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
const int N = 2e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int color[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u,int c,int mid){
    color[u] = c;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(w[i]<=mid)
            continue;
        if(color[j]==0){
            if(!dfs(j,3-c,mid))
                return false;
        }
        else if(color[j]==c)
            return false;
    }
    return true;
}

bool check(int mid){
    memset(color, 0, sizeof color);
    for (int i = 1; i <= n;i++){
        if(color[i]==0){
            if(!dfs(i,1,mid))
                return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w), add(b, a, w);
    }
    int l = 0, r = 1e9;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r;
    return 0;
}