#include<iostream>
#define int long long
const int N=5000005;
using namespace std;
bool prim(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool st[N];
int x[N];
int res,ans;
int n,k;
void dfs(int m,int start){
    if(m>k){
        if(prim(res)) ans++;
        return;
    }
        for(int i=start;i<=n;i++){
            if(! st[i]){
                st[i]=1;
                res+=x[i];
                dfs(m+1,i+1);
                 res-=x[i];
                st[i]=0;
            }
        }
    return;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>x[i];
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
