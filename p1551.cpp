#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
const int N = 5005;
int fa[N],high[N];

void init(int n){
    for (int i = 1; i <= n;i++){
        fa[i] = i;
        high[i] = 1;
    }
}

int find(int x){
    // return x == fa[x] ? x : (fa[x] = find(fa[x]));
    if(x==fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int i,int j){
    int x = find(i), y = find(j);
    if(high[i]<=high[j])
        fa[x] = y;
    else
        fa[y] = x;
    if(high[x]==high[y] && x!=y)
        high[y]++;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, p, x, y;
    cin >> n >> m >> p;
    init(n);
    for (int i = 0; i < m;i++){
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < p;i++){
        cin >> x >> y;
        // cout << (find(x) == find(y) ? "Yes" : "No");
        if(find(x)==find(y))
            cout << "Yes"<<'\n';
        else
            cout << "No"<<'\n';
    }
    return 0;
}