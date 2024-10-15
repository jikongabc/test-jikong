#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e7+10;
const int mod=1e9+7;
int n;
int dp[10010];
bool fun(int x){
    if(x==0){
        return true;
    }
    while(x){
        int a=x%10;
        if(a==0||a==6||a==8||a==9){
            return true;
        }
        x/=10;
    }
    return false;
}
signed  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>n>>m;

    int ans=0;
    for(int i=n;i<=m;i++){
        if(fun(i)){
            ans++;
        }
    }
    cout<<ans;
}
