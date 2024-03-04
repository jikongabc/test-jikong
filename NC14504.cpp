#include<iostream>
#define int long long
using namespace std;
signed main(){
    int n,S,L,i,minn=999999999999,temp,sum,ans;
    cin>>n>>S>>L;
    int a[200005],b[200005];
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
     for(i=1;i<=n;i++){
         minn=0;
        cin>>b[i];
        minn=min(minn,max((S-a[i])/b[i],(L-a[i])/b[i]));
    }
    int l=0,r=minn;
    while(l<=r){
        int mid=(l+r)/2;
        sum=0;
        temp=1e18;
        for(i=1;i<=n;i++){
            a[i]+=b[i]*mid;
            temp=min(temp,a[i]);
            sum+=a[i];
        }
        if(sum>=S && temp>=L){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
