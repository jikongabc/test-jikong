#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5+10;
int n, m;
LL ans;
int a[N], b[N];
int st[N];
void dfs(int x){
    if(x>m){
        int c[N]={0};
        for (int i = 1; i <= m; i++){
            if(st[i]==1){
                for (int j = min(a[i],b[i]); j <= max(b[i],a[i]);j++){
                    c[j]++;
                }
            }
        }
        for (int i = 1; i <= n;i++){
            if(c[i]<2)
                return;
        }
        ans++;
        return;
    }
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        cin >> a[i] >> b[i];
    }
    dfs(1);
    cout << (ans % 998244353);
    return 0;
}