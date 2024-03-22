#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
#define int long long
using namespace std;
const int N = 1005;
int fa[N], high[N];
int X[N], Y[N], Z[N];
bool next(int x1, int y1, int z1, int x2, int y2, int z2, int r)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
}

void init(int n){
    for (int i = 1; i <=n ;i++){
        fa[i] = i;
        high[i] = 1;
    }
}

int find(int x){
    if(x==fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int i,int j){
    int x = find(i), y = find(j);
    if(high[x]<=high[y])
        fa[x] = y;
    else
        fa[y] = x;
        if(high[x]==high[y] && x!=y)
            high[y]++;
}

signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,n,h,r;
    cin >> t;
    while(t--){
        memset(X, 0, sizeof X);
        memset(Y, 0, sizeof Y);
        memset(Z, 0, sizeof Z);
        cin >> n >> h >> r;
        init(n);
        fa[1001] = 1001;
        fa[1002] = 1002;
        for (int i = 1; i <= n;i++){
            // cin >> X[i] >> Y[i] >> Z[i];
            scanf("%lld%lld%lld", X + i, Y + i, Z + i);
        }
        for (int i = 1; i <= n;i++){
            if(Z[i]<=r)
                merge(i, 1001);
            if(Z[i]+r>=h)
                merge(i, 1002);
        }
        for (int i = 1; i <= n;i++){
            for (int j = i+1; j <= n;j++){
                if(next(X[i],Y[i],Z[i],X[j],Y[j],Z[j],r))
                    merge(i, j);
            }
        }
        if(find(1001)==find(1002))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}