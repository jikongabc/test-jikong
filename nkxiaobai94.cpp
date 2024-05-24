#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 2e5 + 10;
int n, k;
int v[N], w[N];
int dp[N];
int st[N];
int maxn;

void dfs(int u){
    if(u>n){
        int cnt = 0;
        int res, ans;
        for (int i = 1; i <= n;i++){
            if(st[i]==1){
                if(!cnt){
                    res = w[i];
                    ans = v[i];
                    if (res > k)
                        return;
                    cnt++;
                }
                else{
                    if (res > k)
                        return;
                    res &= w[i];
                    ans &= v[i];
                    cnt++;
                }
            }
        }
        if(cnt==0 || cnt==1)
            return;
        maxn = max(maxn, ans);
        return;
    }
    st[u] = 1;
    dfs(u + 1);
    st[u] = 2;
    dfs(u + 1);
    st[u] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> w[i] >> v[i];
    }
    dfs(1);
    cout << maxn;
    return 0;
}