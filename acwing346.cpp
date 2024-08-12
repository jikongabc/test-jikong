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
typedef pair<int, int> PII;
const int N = 6005;
int m;
int fa[N], cnt[N];

struct Edge{
    int a, b, w;
    bool operator < (const Edge &t) const{
        return w < t.w;
    }
} edges[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    int res = 0;
    sort(edges, edges + m-1);
    for (int i = 0; i < m-1;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            res += (cnt[a] * cnt[b] - 1) * (w + 1);
            cnt[b] += cnt[a];
            fa[a] = b;
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        for (int i = 1; i <= N;i++){
            fa[i] = i;
            cnt[i] = 1;
        }
        cin >> m;
        for (int i = 0; i < m-1;i++){
            int a, b, w;
            cin >> a >> b >> w;
            edges[i] = {a, b, w};
        }
        cout << kruskal() << endl;
    }
    return 0;
}
