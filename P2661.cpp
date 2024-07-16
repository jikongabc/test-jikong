#include <iostream>
#include <algorithm>
#include <cstring>
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
const int N = 2e5 + 10;
int n;
int res = inf;
int a[N];
int fa[N];
int d[N];

int find(int x){
    if(fa[x]!=x){
        int tmp = fa[x];
        fa[x] = find(fa[x]);
        d[x] += d[tmp];
    }
    return fa[x];
}

void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa!=pb){
        fa[pa] = pb;
        d[a] = d[b] + 1;
    }
    else
        res = min(res, d[a] + d[b] + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        merge(i, a[i]);
    }

    cout << res;
    return 0;
}