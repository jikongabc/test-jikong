#include<iostream>
#define int long long
using namespace std;
int a[300005];
int n,m,d;
bool check(int k)
{
    for (int i = k; i <= m+2; i++)
    {
        if (a[i] - a[i - k] > d) return false;
    }
    return true;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int i,ans=0;
        cin>>n>>m>>d;
        for(i=0;i<m+2;i++){
            cin>>a[i];
        }
        
        int l=0,r=m;
        while(l<=r){
            int mid=(l+r)/2;
//            check=1;
//            for(i=mid;i<=m+2;i++){
//                if(a[i]-a[i-mid]>d){
//                    check=0;
//                }
//            }
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
