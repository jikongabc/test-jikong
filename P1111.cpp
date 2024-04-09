#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1005;
int n, m;
int fa[N];
int ans;

struct node{
    int a, b, t;
} p[N];

bool cmp(node x,node y){
    return x.t < y.t;
}

void init(int n){
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
}

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int i,int j){
    fa[find(i)] = find(j);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m;i++){
        cin >> p[i].a >> p[i].b >> p[i].t;
    }
    sort(p + 1, p + 1 + m, cmp);
    for (int i = 1; i <= m;i++){
        int xx = find(p[i].a), yy = find(p[i].b);
        if(xx!= yy){
            fa[xx] = p[i].b;
            n--;
            if (n == 1){
                cout << p[i].t;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}