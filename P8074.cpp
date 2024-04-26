#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cmath>
#include<unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 10, M = 1e6 + 10;

struct node{
    int x, y, z, id;
} p[N];

struct Edges{
    int a, b, w;
} edges[M];

bool cmp(Edges a,Edges b){
    return a.w < b.w;
}

bool cmpx(node a,node b){
    return a.x < b.x;
}
bool cmpy(node a,node b){
    return a.y < b.y;
}
bool cmpz(node a,node b){
    return a.z < b.z;
}

int n;
int cnt;
int fa[N];

int find(int x){
    if(fa[x]!=x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    int res = 0;
    sort(edges, edges + cnt, cmp);
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 0; i < cnt;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b){
            fa[a] = b;
            res += w;
        }
    } 
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = {x, y, z, i};
    }
    sort(p + 1, p + 1 + n, cmpx);
    for (int i = 1; i < n; i++){
        int w = min({abs(p[i].x - p[i+1].x), abs(p[i].y - p[i+1].y), abs(p[i].z - p[i+1].z)});
        ;
        edges[cnt++] = {p[i].id, p[i + 1].id, w};
    }
    sort(p + 1, p + 1 + n, cmpy);
    for (int i = 1; i < n; i++){
        int w = min({abs(p[i].x - p[i+1].x), abs(p[i].y - p[i+1].y), abs(p[i].z - p[i+1].z)});
        ;
        edges[cnt++] = {p[i].id, p[i + 1].id, w};
    }
    sort(p + 1, p + 1 + n, cmpz);
    for (int i = 1; i < n; i++){
        int w = min({abs(p[i].x - p[i+1].x), abs(p[i].y - p[i+1].y), abs(p[i].z - p[i+1].z)});
        ;
        edges[cnt++] = {p[i].id, p[i + 1].id, w};
    }
    cout << kruskal() << endl;
    for (int i = 0; i < cnt;i++)
        cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w << endl;
        return 0;
}
